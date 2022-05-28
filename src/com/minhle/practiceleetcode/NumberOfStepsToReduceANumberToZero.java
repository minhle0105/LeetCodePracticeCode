package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class NumberOfStepsToReduceANumberToZero {
    public int numberOfSteps(int num) {
        return countStepToReduce(num, 0);
    }

    private int countStepToReduce (int num, int count) {
        if (num <= 0) return count;
        if (num % 2 == 0) return countStepToReduce(num / 2, count + 1);
        return countStepToReduce(num - 1, count + 1);
    }

    @Test
    void test() {
        int num1 = 14;
        int expected1 = 6;
        int actual1 = numberOfSteps(num1);
        int num2 = 8;
        int expected2 = 4;
        int actual2 = numberOfSteps(num2);
        int num3 = 123;
        int expected3 = 12;
        int actual3 = numberOfSteps(num3);
        Assertions.assertTrue(expected1 == actual1 && expected2 == actual2 && expected3 == actual3);
    }
}
