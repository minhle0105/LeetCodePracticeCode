package com.minhle.practiceleetcode;

import java.util.Arrays;

public class ShortestUnsortedContinuousSubarray {
    public int findUnsortedSubarray(int[] nums) {
        int[] numsClone = new int[nums.length];
        System.arraycopy(nums, 0, numsClone, 0, nums.length);
        Arrays.sort(numsClone);

        int left = -1;
        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] != numsClone[i]) {
                left = i;
                break;
            }
        }

        int right = -1;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] != numsClone[i]) {
                right = i;
                break;
            }
        }
        return right != -1 & left != -1 ? right - left + 1 : 0;
    }
}
