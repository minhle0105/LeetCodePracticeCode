import pandas as pd

def change_null_values(coffee_shop: pd.DataFrame) -> pd.DataFrame:
    ids = coffee_shop['id']
    drinks = coffee_shop['drink']
    data = [[id, drink] for id, drink in zip(ids, drinks)]
    for i in range(1, len(data)):
        if data[i][1] == None:
            data[i][1] = data[i - 1][1]
    return pd.DataFrame(data, columns = ['id', 'drink'])
