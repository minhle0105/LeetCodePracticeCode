package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class SearchInSortedArray {

    private int getBreakIndex(int[] nums) {
        int breakIndex = -1;

        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid == nums.length - 1) {
                break;
            }
            if (nums[mid] > nums[mid+1]) {
                breakIndex = mid + 1;
                break;
            }
            else {
                if (nums[mid] < nums[left]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return breakIndex;
    }

    public int search(int[] nums, int target) {
        // first, the array might be rotated so we find the index at which the array was rotated
        int breakIndex = getBreakIndex(nums);

        // if breakIndex != -1, then the array was rotated, we perform binary search with left and right part
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

        // else, the array is already sorted, we perform an original binary search with the whole array
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
