package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ProductOfArrayExceptSelf {
    public int[] productExceptSelf(int[] nums) {
        int[] productFromLeft = new int[nums.length];
        productFromLeft[0] = 1;
        int productLeft = 1;
        int productRight = 1;
        for (int i = 1; i < productFromLeft.length; i++) {
            productLeft *= nums[i - 1];
            productFromLeft[i] = productLeft;
        }

        for (int i = productFromLeft.length - 1; i >= 0; i--) {
            productFromLeft[i] = productFromLeft[i] * productRight;
            productRight *= nums[i];
        }

        return productFromLeft;
    }

    @Test
    void firstTest() {
        int[] nums = {1,2,3,4};
        int[] expected = {24,12,8,6};
        int[] actual = productExceptSelf(nums);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void divideBy0() {
        int[] nums = {-1,1,0,-3,3};
        int[] expected = {0,0,9,0,0};
        int[] actual = productExceptSelf(nums);
        Assertions.assertArrayEquals(expected, actual);
    }

}
