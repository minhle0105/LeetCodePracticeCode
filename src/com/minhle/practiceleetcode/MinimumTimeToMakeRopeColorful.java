package com.minhle.practiceleetcode;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;
public class MinimumTimeToMakeRopeColorful {
    public int minCost(String colors, int[] neededTime) {
        int r = 0;
        int totalTime = 0;
        for (int time : neededTime) {
            totalTime += time;
        }
        int maxTime;
        while (r < neededTime.length) {
            int l = r + 1;
            while (l < neededTime.length && colors.charAt(l) == colors.charAt(r)) {
                l++;
            }
            maxTime = Integer.MIN_VALUE;
            for (int i = r; i < l; i++) {
                maxTime = Math.max(maxTime, neededTime[i]);
            }
            totalTime -= maxTime;
            r = l;
        }

        return totalTime;
    }

    @Test
    void test0() {
        String colors = "abaac";
        int[] neededTime = {1,2,3,4,5};
        Assertions.assertEquals(3, minCost(colors, neededTime));
    }

    @Test
    void test1() {
        String colors = "abc";
        int[] neededTime = {1,2,3};
        Assertions.assertEquals(0, minCost(colors, neededTime));
    }

    @Test
    void test2() {
        String colors = "aabaa";
        int[] neededTime = {1,2,3,4,1};
        Assertions.assertEquals(2, minCost(colors, neededTime));
    }

    @Test
    void test3() {
        String colors = "bbbaaa";
        int[] neededTime = {4,9,3,8,8,9};
        Assertions.assertEquals(23, minCost(colors, neededTime));
    }
}
