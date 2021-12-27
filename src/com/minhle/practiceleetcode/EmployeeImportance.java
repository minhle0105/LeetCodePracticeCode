package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;

    public Employee(int id, int importance, List<Integer> subordinates) {
        this.id = id;
        this.importance = importance;
        this.subordinates = subordinates;
    }
}

public class EmployeeImportance {

    private static Map<Integer, Employee> prepareData(List<Employee> employees, int id) {
        Map<Integer, Employee> employeeHashMap = new HashMap<>();
        for (Employee e : employees) {
            employeeHashMap.put(e.id, e);
        }
        return employeeHashMap;
    }

    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> employeeHashMap = prepareData(employees, id);
        return dfsR(employeeHashMap, id);
    }

    private static int dfsR(Map<Integer, Employee> employeeHashMap, int id) {
        Employee e = employeeHashMap.get(id);
        int result = e.importance;
        for (Integer employeeId : e.subordinates) {
            result += dfsR(employeeHashMap, employeeId);
        }
        return result;
    }

    @Test
    void failedTest() {
        Employee e1 = new Employee(1, 5, new ArrayList<>());
        Employee e2 = new Employee(2, 3, new ArrayList<>());
        Employee e3 = new Employee(3, 4, new ArrayList<>());
        Employee e4 = new Employee(4, 1, new ArrayList<>());
        e1.subordinates.add(2);
        e1.subordinates.add(3);
        e2.subordinates.add(4);
        int expected = 13;
        List<Employee> employees = new ArrayList<>();
        employees.add(e1);
        employees.add(e2);
        employees.add(e3);
        employees.add(e4);
        int actual = getImportance(employees, 1);
        Assertions.assertEquals(expected, actual);
    }
}
