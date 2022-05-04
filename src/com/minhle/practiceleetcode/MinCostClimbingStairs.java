package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class MinCostClimbingStairs {

    public int minCostClimbingStairs(int[] cost) {
        int[] minCost = new int[cost.length + 1];
        for (int i = 2; i < minCost.length; i++) {
            int a = minCost[i - 1] + cost[i - 1];
            int b = minCost[i - 2] + cost[i - 2];
            minCost[i] = Math.min(a, b);
        }
        return minCost[cost.length];
    }

    @Test
    void test1() {
        int[] cost = {1,100,1,1,1,100,1,1,100,1};
        int expected = 6;
        int actual = minCostClimbingStairs(cost);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] cost = {10,15,20};
        int expected = 15;
        int actual = minCostClimbingStairs(cost);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int[] cost = {1,3,2,5,6,10,4};
        int expected = 13;
        int actual = minCostClimbingStairs(cost);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest() {
        int[] cost = {0,1,2,2};
        int expected = 2;
        int actual = minCostClimbingStairs(cost);
        Assertions.assertEquals(expected, actual);
    }
}
// 0 1 2 2