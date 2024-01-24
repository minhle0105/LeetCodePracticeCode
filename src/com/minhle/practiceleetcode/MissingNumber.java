package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class MissingNumber {

    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        if (nums[nums.length - 1] != n) {
            return n;
        }
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i + 1] != nums[i] + 1) {
                return nums[i] + 1;
            }
        }
        return 0;
    }

    @Test
    void firstTest() {
        int[] nums = {3,0,1};
        int expected = 2;
        int actual = missingNumber(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] nums = {0,1};
        int expected = 2;
        int actual = missingNumber(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3 () {
        int[] nums = {9,6,4,2,3,5,7,0,1};
        int expected = 8;
        int actual = missingNumber(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test4() {
        int[] nums = {0};
        int expected = 1;
        int actual = missingNumber(nums);
        Assertions.assertEquals(expected, actual);
    }
}
