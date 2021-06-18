package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class ClimbingStairs {

    public int fibonacci(int n) {
        int[] results = new int[n+1];
        results[0] = 1;
        results[1] = 1;
        for (int i = 2; i <= n; i++) {
            results[i] = results[i-1] + results[i-2];
        }
        return results[n];
    }

    public int climbStairs(int n) {
        return fibonacci(n);
    }

    @Test
    void rawTest() {
        int expected = 8;
        int actual = climbStairs(5);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int expected = 13;
        int actual = climbStairs(6);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void aggTest() {
        int[] expected = {1,2,3};
        int actual1 = climbStairs(1);
        int actual2 = climbStairs(2);
        int actual3 = climbStairs(3);
        int[] actuals = {actual1, actual2, actual3};
        Assertions.assertEquals(Arrays.toString(expected), Arrays.toString(actuals));
    }

    @Test
    void failedTest() {
        int expected = 5;
        int actual = climbStairs(4);
        Assertions.assertEquals(expected, actual);
    }
}
