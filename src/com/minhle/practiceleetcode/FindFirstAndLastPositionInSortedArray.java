package com.minhle.practiceleetcode;

public class FindFirstAndLastPositionInSortedArray {
    public int[] searchRange(int[] nums, int target) {
        int[] results = new int[2];
        return new int[]{binarySearchFirst(nums, target), binarySearchLast(nums, target)};
    }

    private int binarySearchFirst(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((mid == left || target > nums[mid - 1]) && nums[mid] == target) {
                return mid;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    private int binarySearchLast(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((mid == right || target < nums[mid + 1]) && nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
}
