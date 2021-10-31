package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class SubArraySumEqualsK {

    public int subarraySum(int[] nums, int k) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            for (int j = i; j < nums.length; j++) {
                sum += nums[j];
                if (sum == k) {
                    result++;
                }
            }
        }
        return result;
    }

    @Test
    void firstTest () {
        int[] nums = {1,2,3};
        int k = 3;
        int expected = 2;
        int actual = subarraySum(nums, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failTest() {
        int[] nums = {1,-1,0};
        int k = 0;
        int expected = 3;
        int actual = subarraySum(nums, k);
        Assertions.assertEquals(expected, actual);
    }
}
