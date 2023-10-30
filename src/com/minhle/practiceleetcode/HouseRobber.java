package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class HouseRobber {
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[1], nums[0]);
        for (int i = 2; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.length - 1];
    }

    @Test
    void test1() {
        int[] nums = {1,2,3,1};
        int expected = 4;
        int actual = rob(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] nums = {2,7,9,3,1};
        int expected = 12;
        int actual = rob(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int[] nums = {2,1,1,2};
        int expected = 4;
        int actual = rob(nums);
        Assertions.assertEquals(expected, actual);
    }
}