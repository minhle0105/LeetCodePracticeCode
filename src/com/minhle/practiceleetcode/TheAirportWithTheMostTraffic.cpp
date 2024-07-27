import pandas as pd

def airport_with_most_traffic(flights: pd.DataFrame) -> pd.DataFrame:
    departures = list(flights['departure_airport'])
    arrivals = list(flights['arrival_airport'])
    flights = list(flights['flights_count'])

    counter = dict()
    for i in range(len(flights)):
        if departures[i] not in counter:
            counter[departures[i]] = 0
        counter[departures[i]] += flights[i]
        if arrivals[i] not in counter:
            counter[arrivals[i]] = 0
        counter[arrivals[i]] += flights[i]

    max_flight = 0
    for pairs in counter.items():
        max_flight = max(max_flight, pairs[1])
    
    airport_with_max_flight = []
    for pairs in counter.items():
        if pairs[1] == max_flight:
            airport_with_max_flight.append(pairs[0])
    
    res = {'airport_id': airport_with_max_flight}

    return pd.DataFrame(res)
    

