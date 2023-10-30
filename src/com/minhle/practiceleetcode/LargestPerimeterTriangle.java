package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class LargestPerimeterTriangle {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length - 3;
        for (int i = n; i >= 0; i--) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }

    @Test
    void test1() {
        int[] nums = {2,1,2};
        int expected = 5;
        int actual = largestPerimeter(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] nums = {1,2,1};
        int expected = 0;
        int actual = largestPerimeter(nums);
        Assertions.assertEquals(expected, actual);
    }
}
