import pandas as pd

def find_manager(employees: pd.DataFrame) -> pd.DataFrame:
    managers = dict()
    for index, rows in employees.iterrows():
        if rows.iloc[-1] == "Manager":
            dept_id = rows.iloc[-2]
            if dept_id not in managers:
                managers[dept_id] = [rows.iloc[0], rows.iloc[1]]
    
    largest_dept = find_largest_dept(employees)

    res = [[managers[dept][1], dept] for dept in largest_dept]
    res.sort(key=lambda x: x[1])

    return pd.DataFrame(data=res, columns=['manager_name', 'dep_id'])


def find_largest_dept(employees):
    dept_sizes = dict()
    max_size = 0
    for index, rows in employees.iterrows():
        dept_id = rows.iloc[2]
        if dept_id not in dept_sizes:
            dept_sizes[dept_id] = 0
        dept_sizes[dept_id] += 1
        max_size = max(max_size, dept_sizes[dept_id])
    
    largest_dept = []
    for items in dept_sizes.items():
        if items[1] == max_size:
            largest_dept.append(items[0])

    return largest_dept

