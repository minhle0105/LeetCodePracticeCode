package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class MaximumProductDifference {
    public int maxProductDifference(int[] nums) {
        int[] maxProduct = new int[2];
        maxProduct[0] = nums[0];
        maxProduct[1] = nums[1];
        int currentMaxProduct = maxProduct[0] * maxProduct[1];
        int greaterNumInMax = Math.max(maxProduct[0], maxProduct[1]);

        int[] minProduct = new int[2];
        minProduct[0] = nums[0];
        minProduct[1] = nums[1];
        int currentMinProduct = minProduct[0] * minProduct[1];
        int smallerNumInMin = Math.min(minProduct[0], minProduct[1]);

        for (int i = 2; i < nums.length; i++) {
            if (nums[i] * greaterNumInMax > currentMaxProduct) {
                maxProduct[0] = greaterNumInMax;
                maxProduct[1] = nums[i];
                currentMaxProduct = maxProduct[0] * maxProduct[1];
                greaterNumInMax = Math.max(maxProduct[0], maxProduct[1]);
            }
            if (nums[i] * smallerNumInMin <= currentMinProduct) {
                minProduct[0] = smallerNumInMin;
                minProduct[1] = nums[i];
                currentMinProduct = minProduct[0] * minProduct[1];
                smallerNumInMin = Math.min(minProduct[0], minProduct[1]);
            }
        }
        return currentMaxProduct - currentMinProduct;
    }

    @Test
    void firstTest() {
        int[] nums = {5,6,2,7,4};
        int expected = 34;
        int actual = maxProductDifference(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[] nums = {4,2,5,9,7,4,8};
        int expected = 64;
        int actual = maxProductDifference(nums);
        Assertions.assertEquals(expected, actual);
    }
}
