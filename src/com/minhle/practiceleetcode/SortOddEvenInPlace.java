package com.minhle.practiceleetcode;

public class SortOddEvenInPlace {
    /**
     * Sort data such that all odd numbers come first, sorted descendingly, and then all even numbers
     * come after, sorted ascendingly, without using subarray;
     * @param nums
     */
    private static void sort(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (right > left) {
            while (nums[right] % 2 == 0) {
                right--;
                if (right == left) {
                    break;
                }
            }
            if (right == left) {
                break;
            }
            while (nums[left] % 2 != 0) {
                left++;
                if (right == left) {
                    break;
                }
            }
            if (right == left) {
                break;
            }
            if (nums[left] % 2 != 0 && nums[right] % 2 == 0) {
                break;
            }
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            right--;
            left++;
        }
        sortDescendingly(nums, left + 1);
        sortAscendingly(nums, left + 1);
    }

    private static void sortAscendingly(int[] nums, int threshold) {
        for (int i = threshold; i < nums.length - 1; i++) {
            int minVal = nums[i];
            int minInd = i;
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] < minVal) {
                    minVal = nums[j];
                    minInd = j;
                }
            }
            int temp = nums[i];
            nums[i] = minVal;
            nums[minInd] = temp;
        }
    }


    private static void sortDescendingly(int[] nums, int threshold) {
        for (int i = 0; i < threshold - 1; i++) {
            int maxVal = nums[i];
            int maxInd = i;
            for (int j = i + 1; j < threshold; j++) {
                if (nums[j] > maxVal) {
                    maxVal = nums[j];
                    maxInd = j;
                }
            }
            int temp = nums[i];
            nums[i] = maxVal;
            nums[maxInd] = temp;
        }
    }
}
