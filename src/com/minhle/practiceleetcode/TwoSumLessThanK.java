package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

public class TwoSumLessThanK {
    public int twoSumLessThanK(int[] nums, int k) {
        int result = -1;
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++)  {
                if (nums[i] + nums[j] < k && nums[i] + nums[j] > result) {
                    result = nums[i] + nums[j];
                }
            }
        }
        return result;
    }

    @Test
    void test1() {
        int[] nums = {34,23,1,24,75,33,54,8};
        int k = 60;
        int expected = 58;
        int actual = twoSumLessThanK(nums, k);
    }

    @Test
    void test2() {
        int[] nums = {10, 20, 30};
        int k = 15;
        int expected = -1;
        int actual = twoSumLessThanK(nums, k);
    }
}
