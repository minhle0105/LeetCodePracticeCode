package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SubarrayProductLessThanK {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int prod = 1;
        int count = 0;
        int left = 0;
        for (int right = 0; right < nums.length; right++) {
            prod *= nums[right];
            while (prod >= k) {
                prod /= nums[left++];
                count += right - left + 1;
            }
        }
        return count;
    }

    @Test
    void test1() {
        int[] nums = {1,2,3};
        int k = 0;
        Assertions.assertEquals(0, numSubarrayProductLessThanK(nums, k));
    }

}
