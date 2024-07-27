import pandas as pd

def find_categories(members: pd.DataFrame, visits: pd.DataFrame, purchases: pd.DataFrame) -> pd.DataFrame:
    member_ids = list(members['member_id'])
    member_names = list(members['name'])

    member_info = dict()
    for i in range(len(member_ids)):
        member_info[member_ids[i]] = member_names[i]
    
    conversion_rates = calculate_conversion_rate(visits, purchases)

    types_mapping = dict()

    for pairs in member_info.items():
        member_id = pairs[0]
        if member_id not in conversion_rates:
            types_mapping[member_id] = 'Bronze'
        else:
            conversion_rate = conversion_rates[member_id]
            if conversion_rate >= 80:
                types_mapping[member_id] = 'Diamond'
            elif conversion_rate >= 50 and conversion_rate < 80:
                types_mapping[member_id] = 'Gold'
            elif conversion_rate < 50:
                types_mapping[member_id] = 'Silver'

    res_ids = []
    res_names = []
    res_categories = []
    for pairs in types_mapping.items():
        res_ids.append(pairs[0])
        res_names.append(member_info[pairs[0]])
        res_categories.append(pairs[1])
    
    res = {'member_id': res_ids, 'name': res_names, 'category': res_categories}
    return pd.DataFrame(res)




def calculate_conversion_rate(visits: pd.DataFrame, purchases: pd.DataFrame):
    visit_ids = list(visits['visit_id'])
    member_ids = list(visits['member_id'])

    visit_per_member = dict()

    for i in range(len(member_ids)):
        if member_ids[i] not in visit_per_member:
            visit_per_member[member_ids[i]] = []
        visit_per_member[member_ids[i]].append(visit_ids[i])
    
    purchases_visit_ids = set(purchases['visit_id'])

    purchase_per_member = dict()

    for pairs in visit_per_member.items():
        member_id = pairs[0]
        if member_id not in purchase_per_member:
            purchase_per_member[member_id] = 0
        for visit_id in pairs[1]:
            if visit_id in purchases_visit_ids:
                purchase_per_member[member_id] += 1
    
    conversion_rate = dict()

    for pairs in visit_per_member.items():
        member_id = pairs[0]
        total_visit = len(pairs[1])
        total_purchase_count = purchase_per_member[member_id]

        conversion_rate[member_id] = (100.0 * total_purchase_count) / total_visit
    
    return conversion_rate
    


