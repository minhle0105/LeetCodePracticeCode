package com.minhle.practiceleetcode;
import static org.junit.jupiter.api.Assertions.assertEquals;
import org.junit.jupiter.api.Test;

import static java.lang.Math.*;

public class MaximumSubarray {
    public int maxSubArray(int[] nums) {
        int result = nums[0];
        int[] subArraySum = new int[nums.length];
        subArraySum[0] = nums[0];
        int currentStartIndex = 1;
        for(int i = currentStartIndex; i < nums.length; i++) {
            if (nums[i] > subArraySum[i-1] + nums[i]) {
                currentStartIndex = i;
                subArraySum[i] = nums[i];
            }
            else {
                subArraySum[i] = subArraySum[i-1] + nums[i];
            }
        }
        for (Integer i : subArraySum) {
            if (i > result) {
                result = i;
            }
        }
        return result;
    }

    @Test
    void firstTest() {
        int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
        int expected = 6;
        int actual = maxSubArray(nums);
        assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[] nums = {1};
        int expected = 1;
        int actual = maxSubArray(nums);
        assertEquals(expected, actual);
    }

    @Test
    void failedTest() {
        int[] nums = {1,2};
        int expected = 3;
        int actual = maxSubArray(nums);
        assertEquals(expected, actual);
    }

    @Test
    void lastTest() {
        int[] nums = {5,4,-1,7,8};
        int expected = 23;
        int actual = maxSubArray(nums);
        assertEquals(expected, actual);
    }
}
