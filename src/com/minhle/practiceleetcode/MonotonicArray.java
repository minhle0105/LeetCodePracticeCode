package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class MonotonicArray {
    public boolean isMonotonic(int[] nums) {
        int index = 0;
        int sign = -1;
        while (index < nums.length - 1) {
            if (nums[index + 1] - nums[index] != 0) {
                sign = nums[index + 1] - nums[index];
                break;
            }
            index++;
        }
        if (sign > 0) {
            for (int i = 0; i < nums.length - 2; i++) {
                if (nums[i] <= nums[i+1] && !(nums[i + 1] <= nums[i + 2]) ) {
                    return false;
                }
            }
        }
        else {
            for (int i = 0; i < nums.length - 2; i++) {
                if (nums[i] >= nums[i + 1] && !(nums[i + 1] >= nums[i + 2])) {
                    return false;
                }
            }
        }
        return true;
    }

    @Test
    void test1() {
        int[] nums = {1,2,2,3};
        Assertions.assertTrue(isMonotonic(nums));
    }

    @Test
    void test2() {
        int[] nums = {6,5,4,4};
        Assertions.assertTrue(isMonotonic(nums));
    }

    @Test
    void test3() {
        int[] nums = {1,3,2};
        Assertions.assertFalse(isMonotonic(nums));
    }
}
