package com.minhle.practiceleetcode;
import static org.junit.jupiter.api.Assertions.assertEquals;
import org.junit.jupiter.api.Test;

public class MaximumSubarray {
    public int maxSubArray(int[] nums) {
        int result = nums[0];
        int[] subArraySum = new int[nums.length];
        subArraySum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int sumIfStartFromHere = nums[i];
            int sumIfContinue = nums[i] + subArraySum[i - 1];
            subArraySum[i] = Math.max(sumIfStartFromHere, sumIfContinue);
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
