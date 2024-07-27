import pandas as pd

def number_of_calls(calls: pd.DataFrame) -> pd.DataFrame:
    froms = list(calls['from_id'])
    tos = list(calls['to_id'])
    caller_pairs = [(min(froms[i], tos[i]), max(froms[i], tos[i])) for i in range(len(froms))]
    durations = list(calls['duration'])
    pos = 0
    total_time = dict()
    counter = dict()
    for pair in caller_pairs:
        if pair not in counter:
            counter[pair] = 0
        if pair not in total_time:
            total_time[pair] = 0
        counter[pair] += 1
        total_time[pair] += durations[pos]
        pos += 1
    
    all_person_1 = []
    all_person_2 = []
    all_call_count = []
    all_total_duration = []

    for pairs in counter.items():
        person1 = pairs[0][0]
        person2 = pairs[0][1]
        count = pairs[1]
        total_duration = total_time[pairs[0]]

        all_person_1.append(person1)
        all_person_2.append(person2)
        all_call_count.append(count)
        all_total_duration.append(total_duration)

    res = {'person1': all_person_1, 'person2': all_person_2, 'call_count': all_call_count, 'total_duration': all_total_duration}

    return pd.DataFrame(res)
