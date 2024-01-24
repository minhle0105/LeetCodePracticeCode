package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class BinarySearch {
    public int search(int[] nums, int target) {
        if (nums.length == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) {
                return middle;
            }
            else if (target < nums[middle]) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return -1;
    }

    @Test
    void firstTest() {
        int[] nums = {-1,0,3,5,9,12};
        int target = 2;
        int expected = -1;
        Assertions.assertEquals(search(nums, target), expected);
    }

    @Test
    void secondTest() {
        int[] nums = {-1,0,3,5,9,12};
        int target = 13;
        int expected = -1;
        Assertions.assertEquals(search(nums, target), expected);
    }

    @Test
    void failTest() {
        int[] nums = {-1,0,3,5,9,12};
        int target = 9;
        int expected = 4;
        Assertions.assertEquals(search(nums, target), expected);
    }
}
