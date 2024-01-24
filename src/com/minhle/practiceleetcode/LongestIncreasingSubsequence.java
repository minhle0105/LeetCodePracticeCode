package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class LongestIncreasingSubsequence {
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 1) {
            return 1;
        }
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);
        int i = 0;
        int j = i + 1;
        while (j < nums.length) {
            while (i < j) {
                if (nums[j] > nums[i]) {
                    dp[j] = Math.max(dp[i] + 1, dp[j]);
                }
                i++;
            }
            i = 0;
            j++;
        }
        int res = Integer.MIN_VALUE;
        for (int d : dp) {
            res = Math.max(d, res);
        }
        return res;
    }

    @Test
    void test1() {
        int[] nums = {10,9,2,5,3,7,101,18};
        Assertions.assertEquals(4, lengthOfLIS(nums));
    }

    @Test
    void test2() {
        int[] nums = {0,1,0,3,2,3};
        Assertions.assertEquals(4, lengthOfLIS(nums));
    }

    @Test
    void test3() {
        int[] nums = {7,7,7,7,7,7,7};
        Assertions.assertEquals(1, lengthOfLIS(nums));
    }

    @Test
    void test4() {
        int[] nums = {-1,3,4,5,2,2,2,2};
        Assertions.assertEquals(4, lengthOfLIS(nums));
    }
}
