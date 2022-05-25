package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class IntersectionOfThreeSortedArrays {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        List<Integer> contains = new ArrayList<>();
        for (int num : arr1) {
            boolean isInArr2 = binarySearch(arr2, num);
            if (isInArr2) {
                boolean isInArr3 = binarySearch(arr3, num);
                if (isInArr3) {
                    contains.add(num);
                }
            }
        }
        return contains;
    }

    private boolean binarySearch(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
}
