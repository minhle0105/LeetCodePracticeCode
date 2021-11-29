package com.minhle.practiceleetcode;

import java.util.Arrays;

public class SlidingWindowMaximum {
    private static int findMax(int[] nums) {
        int maxVal = nums[0];
        for (int i : nums) {
            if (i > maxVal) {
                maxVal = i;
            }
        }
        return maxVal;
    }

    public static int[] maxSlidingWindow(int[] nums, int k) {
        int[] results = new int[nums.length - k + 1];
        int count = 0;
        for (int i = 0; i < nums.length - k + 1; i++) {
            int[] sub = Arrays.copyOfRange(nums, i, i + k);
            results[count++] = findMax(sub);
        }
        return results;
    }

    public static void main(String[] args) {
        int[] nums = {1, -1};
        int k = 1;
        int[] results = maxSlidingWindow(nums, k);
        System.out.println(Arrays.toString(results));
    }
}
