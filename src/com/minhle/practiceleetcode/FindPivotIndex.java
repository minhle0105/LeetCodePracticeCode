package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class FindPivotIndex {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int[] leftSum = new int[n + 1];
        int[] rightSum = new int[n + 1];
        int lSum = 0;
        leftSum[0] = 0;
        for (int i = 1; i <= n; i++) {
            leftSum[i] = lSum + nums[i - 1];
            lSum += nums[i - 1];
        }
        int rSum = 0;
        rightSum[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightSum[i] = rSum + nums[i];
            rSum += nums[i];
        }
        for (int i = 0; i < n; i++) {
            int l = leftSum[i];
            int r = rightSum[i + 1];
            if (l == r) {
                return i;
            }
        }
        return -1;
    }
    @Test
    void test1() {
        int[] nums = {1,7,3,6,5,6};
        int expected = 3;
        int actual = pivotIndex(nums);
        Assertions.assertEquals(expected, actual);
    }
    @Test
    void test2() {
        int[] nums = {1,2,3};
        int expected = -1;
        int actual = pivotIndex(nums);
        Assertions.assertEquals(expected, actual);
    }
}
