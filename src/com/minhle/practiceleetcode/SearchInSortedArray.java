package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class SearchInSortedArray {
    public int search(int[] nums, int target) {
        int breakIndex = -1;

        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i+1]) {
                breakIndex = i+1;
                break;
            }
        }

        if (breakIndex != -1) {
            int isInLeftHalf = isInArr(Arrays.copyOfRange(nums, 0, breakIndex), target);
            if (isInLeftHalf != -1) {
                return isInLeftHalf;
            }
            int isInRightHalf = isInArr(Arrays.copyOfRange(nums, breakIndex, nums.length), target);
            if (isInRightHalf != -1) {
                return breakIndex + isInRightHalf;
            }
            return -1;
        }

        else {
            return isInArr(nums, target);
        }

    }


    private int isInArr(int[] nums, int target) {
        if (nums.length == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
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
    void lastTest() {
        int[] nums = {1, 3};
        int target = 3;
        int expected = 1;
        int actual = search(nums, target);
        Assertions.assertEquals(expected, actual);
    }

}
