package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AverageSalaryExcludingMinAndMax {
    public double average(int[] salary) {
        int maxSalary = salary[0];
        int minSalary = salary[0];
        for (int sal : salary) {
            if (sal > maxSalary) {
                maxSalary = sal;
            }
            else if (sal < minSalary) {
                minSalary = sal;
            }
        }
        int sum = 0;
        int count = 0;
        for (int sal : salary) {
            if (sal == maxSalary | sal == minSalary) {
                continue;
            }
            else {
                sum += sal;
                count++;
            }
        }
        return ((double) sum) / count;
    }

    @Test
    void test1() {
        int[] salary = {4000,3000,1000,2000};
        double expected = 2500.00000;
        double actual = average(salary);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] salary = {1000,2000,3000};
        double expected = 2000.00000;
        double actual = average(salary);
        Assertions.assertEquals(expected, actual);
    }
}
