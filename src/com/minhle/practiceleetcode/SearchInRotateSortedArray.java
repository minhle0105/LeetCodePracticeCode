package com.minhle.practiceleetcode;

public class SearchInRotateSortedArray {
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
}
