package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SingleElementInSortedArray {

    public int singleNonDuplicate(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        return binarySearch(0, nums.length - 1, nums);
    }

    private int binarySearch(int left, int right, int[] nums) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (mid > 0 && mid < nums.length - 1 && nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
            return nums[mid];
        }
        else if ((mid == 0 && nums[mid] != nums[mid + 1]) | (mid == nums.length - 1 && nums[mid] != nums[mid - 1])) {
            return nums[mid];
        }
        else {
            int a = binarySearch(left, mid - 1, nums);
            int b = binarySearch(mid + 1, right, nums);
            return a == -1 ? b : a;
        }
    }

    @Test
    void test1() {
        int[] nums = {1,1,2,3,3,4,4,8,8};
        int expected = 2;
        int actual = singleNonDuplicate(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] nums = {3,3,7,7,10,11,11};
        int expected = 10;
        int actual = singleNonDuplicate(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int[] nums = {1,1,2};
        int expected = 2;
        int actual = singleNonDuplicate(nums);
        Assertions.assertEquals(expected, actual);
    }
}
