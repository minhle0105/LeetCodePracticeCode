package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class SearchInSortedArray {

    public int search(int[] nums, int target) {
        int pivot = searchPivot(nums);
        if (pivot == -1) {
            return binarySearch(nums, 0, nums.length - 1, target);
        }
        else {
            int l = binarySearch(nums, 0, pivot - 1, target);
            int r = binarySearch(nums, pivot, nums.length - 1, target);
            return l == -1 ? r : l;
        }
    }

    private int binarySearch(int[] nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, right, target);
        }
        else {
            return binarySearch(nums, left, mid - 1, target);
        }
    }

    private int searchPivot(int[] nums) {
        if (nums.length == 1) return 0;
        if (nums[0] < nums[nums.length - 1]) {
            return 0;
        }
        int pivot = -1;
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return mid + 1;
            }

            if (nums[mid - 1] > nums[mid]) {
                return mid;
            }
            if (nums[mid] > nums[0]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return pivot;
    }

    @Test
    void firstTest() {
        int[] nums = {4,5,6,7,0,1,2};
        int target = 0;
        int expected = 4;
        int actual = search(nums, target);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[] nums = {4,5,6,7,0,1,2};
        int target = 3;
        int expected = -1;
        int actual = search(nums, target);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void sortedArrayTest() {
        int[] nums = {0,1,2,3,4,5};
        int target = 3;
        int expected = 3;
        int actual = search(nums, target);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void lastTest() {
        int[] nums = {5,1,3};
        int target = 5;
        int expected = 0;
        int actual = search(nums, target);
        Assertions.assertEquals(expected, actual);
    }

}
