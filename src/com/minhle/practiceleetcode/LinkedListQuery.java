package com.minhle.practiceleetcode;

import java.util.*;

public class LinkedListQuery {

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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] nums = {6,5,8,12,17,8,4,3,1,5};
        int[] actual = {17,5,5,3,1,4,6,8,8,12};
        int[] nums2 = {6,5,1,3,4,2};
        int[] actual2 = {5,3,1,2,4,6};
        sort(nums);
        sort(nums2);
        sc.close();
        System.out.println(Arrays.equals(actual, nums));
        System.out.println(Arrays.equals(actual2, nums2));
    }
}
