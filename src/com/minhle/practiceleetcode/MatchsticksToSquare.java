package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class MatchsticksToSquare {

    public boolean makesquare(int[] matchsticks) {
        int sum = 0;
        for (int match : matchsticks)
            sum += match;
        if (sum % 4 != 0) return false;
        Arrays.sort(matchsticks);
        reverseArray(matchsticks);
        return backtrack(0, matchsticks, new int[4], sum / 4);
    }

    private boolean backtrack(int i, int[] matches, int[] sides, int length) {
        if (i == matches.length) {
            return true;
        }
        for (int j = 0; j < 4; j++) {
            if (sides[j] + matches[i] <= length) {
                sides[j] += matches[i];
                if (backtrack(i + 1, matches, sides, length)) {
                    return true;
                }
                sides[j] -= matches[i];
            }
        }
        return false;
    }

    private void reverseArray(int[] nums) {
        for (int i = 0; i < nums.length / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[nums.length - i - 1];
            nums[nums.length - i - 1] = temp;
        }
    }

    @Test
    void test1() {
        int[] matchsticks = {1,1,2,2,2};
        Assertions.assertTrue(makesquare(matchsticks));
    }

    @Test
    void test2() {
        int[] matchsticks = {3,3,3,3,4};
        Assertions.assertFalse(makesquare(matchsticks));
    }

    @Test
    void test3() {
        int[] matchsticks = {5,5,5,5,4,4,4,4,3,3,3,3};
        Assertions.assertTrue(makesquare(matchsticks));
    }
}
