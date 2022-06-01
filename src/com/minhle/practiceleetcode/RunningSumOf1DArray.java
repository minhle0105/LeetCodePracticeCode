package com.minhle.practiceleetcode;

public class RunningSumOf1DArray {
    public int[] runningSum(int[] nums) {
        int n = nums.length;
        int[] runningSum = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            runningSum[i] = nums[i] + sum;
            sum = runningSum[i];
        }
        return runningSum;
    }
}
