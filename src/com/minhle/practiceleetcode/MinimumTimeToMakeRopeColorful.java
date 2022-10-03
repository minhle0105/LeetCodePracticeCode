package com.minhle.practiceleetcode;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;
public class MinimumTimeToMakeRopeColorful {
    static class Balloon {
        char color;
        int removedTime;

        public Balloon(char color, int removedTime) {
            this.color = color;
            this.removedTime = removedTime;
        }
    }
    public int minCost(String colors, int[] neededTime) {
        List<List<Balloon>> balloonGroups = new ArrayList<>();
        int r = 0;
        int totalTime = 0;
        List<Balloon> balloons;
        while (r < neededTime.length) {
            balloons = new ArrayList<>();
            int l = r + 1;
            while (l < neededTime.length && colors.charAt(l) == colors.charAt(r)) {
                l++;
            }
            for (int i = r; i < l; i++) {
                totalTime += neededTime[i];
                balloons.add(new Balloon(colors.charAt(r), neededTime[i]));
            }
            balloonGroups.add(balloons);
            r = l;
        }
        for (List<Balloon> group : balloonGroups) {
            int maxTime = Integer.MIN_VALUE;
            for (Balloon balloon : group) {
                maxTime = Math.max(balloon.removedTime, maxTime);
            }
            totalTime -= maxTime;
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
