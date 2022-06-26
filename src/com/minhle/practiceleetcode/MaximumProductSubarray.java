package com.minhle.practiceleetcode;

public class MaximumProductSubarray {

    public int maxProduct(int[] nums) {
        int max = nums[0];

        for (int num : nums) {
            if (num > max) max = num;
        }

        int currentMax = 1;
        int currentMin = 1;

        for (int num : nums) {
            int temp = currentMax * num;
            currentMax = Math.max(num * currentMax, num * currentMin);
            currentMax = Math.max(currentMax, num);
            currentMin = Math.min(temp, num * currentMin);
            currentMin = Math.min(currentMin, num);
            max = Math.max(max, currentMax);
        }

        return max;
    }
}
