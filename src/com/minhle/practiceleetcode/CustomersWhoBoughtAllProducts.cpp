import pandas as pd

def find_customers(customer: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    n_products = len(set(product['product_key']))
    customers = customer['customer_id']
    product_keys = customer['product_key']

    counter = dict()

    for i in range(len(customers)):
        if customers[i] not in counter:
            counter[customers[i]] = set()
        counter[customers[i]].add(product_keys[i])
    
    res = {'customer_id': []}

    for pairs in counter.items():
        if len(pairs[1]) == n_products:
            res['customer_id'].append(pairs[0])
    
    return pd.DataFrame(res)
