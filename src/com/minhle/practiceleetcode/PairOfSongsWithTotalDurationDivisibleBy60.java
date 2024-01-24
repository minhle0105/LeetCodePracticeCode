package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;
import java.util.Map;

public class PairOfSongsWithTotalDurationDivisibleBy60 {
    public int numPairsDivisibleBy60(int[] time) {
        int remainders[] = new int[60];
        int count = 0;
        for (int t: time) {
            if (t % 60 == 0) {
                count += remainders[0];
            } else {
                int target = 60 - t % 60;
                count += remainders[target];
            }
            remainders[t % 60]++;
        }
        return count;
    }

    @Test
    void test1() {
        int[] time = {30,20,150,100,40};
        Assertions.assertEquals(3, numPairsDivisibleBy60(time));
    }

    @Test
    void test2() {
        int[] time = {60,60,60};
        Assertions.assertEquals(3, numPairsDivisibleBy60(time));
    }
}
