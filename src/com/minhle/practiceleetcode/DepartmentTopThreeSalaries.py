import pandas as pd

class Employee:
    def __init__(self, id, name, salary, department_id):
        self.id = id
        self.name = name
        self.salary = salary
        self.department_id = department_id

    def __str__(self):
        return f"Employee: id {self.id}, name {self.name}, salary {self.salary}"

def construct_dept_info(department):
    res = dict()
    ids = list(department['id'])
    names = list(department['name'])

    for i in range(len(ids)):
        res[ids[i]] = names[i]
    
    return res

def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    employee_ids = list(employee['id'])
    employee_names = list(employee['name'])
    employee_salaries = list(employee['salary'])
    dept_ids = list(employee['departmentId'])

    all_employees = [Employee(employee_ids[i], employee_names[i], employee_salaries[i], dept_ids[i]) for i in range(len(employee_ids))]

    employees_by_departments = dict()

    for e in all_employees:
        dept_id = e.department_id
        if dept_id not in employees_by_departments:
            employees_by_departments[dept_id] = []
        employees_by_departments[dept_id].append(e)
    
    for pairs in employees_by_departments.items():
        pairs[1].sort(key=lambda Employee: Employee.salary, reverse=True)
        unique_salary = set()
        last_index = -1
        for i in range(len(pairs[1])):
            if len(unique_salary) == 3 and pairs[1][i].salary not in unique_salary:
                break
            unique_salary.add(pairs[1][i].salary)
            print(unique_salary)
            last_index = i
        employees_by_departments[pairs[0]] = pairs[1][0:last_index + 1]
        
    dept_info = construct_dept_info(department)

    res = []

    for pairs in employees_by_departments.items():
        dept_name = dept_info[pairs[0]]
        for i in range(len(pairs[1])):
            res.append([dept_name, pairs[1][i].name, pairs[1][i].salary])
    
    return pd.DataFrame(data=res, columns=['Department', 'Employee', 'Salary'])
