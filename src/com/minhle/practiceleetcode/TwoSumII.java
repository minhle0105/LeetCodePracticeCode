package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class TwoSumII {

    private int binarySearch(int left, int right, int[] numbers, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] == target) {
                return mid;
            }
            else if (target < numbers[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }

    public int[] twoSum(int[] numbers, int target) {
        int[] result = new int[2];
        for (int i = 0; i < numbers.length - 1; i++) {
            int difference = target - numbers[i];
            int response = binarySearch(i + 1, numbers.length - 1, numbers, difference);
            if (response != -1) {
                return new int[]{i + 1, response + 1};
            }
        }
        return result;
    }

    @Test
    void firstTest() {
        int[] nums = {2,7,11,15};
        int target = 9;
        int[] expected = {1,2};
        int[] actual = twoSum(nums, target);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] nums = {2,3,4};
        int target = 6;
        int[] expected = {1,3};
        int[] actual = twoSum(nums, target);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void test3() {
        int[] nums = {-1, 0};
        int target = -1;
        int[] expected = {1,2};
        int[] actual = twoSum(nums, target);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void test4() {
        int[] nums = {0,0,3,4};
        int target = 0;
        int[] expected = {1,2};
        int[] actual = twoSum(nums, target);
        Assertions.assertArrayEquals(expected, actual);
    }
}
