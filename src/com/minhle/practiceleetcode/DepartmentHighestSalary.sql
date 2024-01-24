WITH highest_salary_per_dept AS
         (SELECT d.name AS DeptName, d.id as DeptId, max(salary) as MaxSalary
          from Employee e
                   JOIN Department d
                        ON e.departmentId = d.id
          GROUP BY d.id)
SELECT DeptName as Department, e.name as Employee, MaxSalary as Salary
FROM highest_salary_per_dept
         JOIN Employee e on e.salary = MaxSalary and DeptId = e.departmentId;