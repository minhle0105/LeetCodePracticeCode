package com.minhle.practiceleetcode;

public class HouseRobberII {
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        boolean firstHouseRobbed = false;

        for (int i = 2; i < nums.length; i++) {
            if (i == 2) {
                if (nums[i] + dp[i - 2] > dp[i - 1]) {
                    firstHouseRobbed = true;
                }
            }
            dp[i] = Math.max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        // if firstHouse is robbed -> we can't rob the last house, so we will see if the result changes if we don't rob the fisrt house -> we will rob the last house instead
        if (firstHouseRobbed) {
            int[] newDp = new int[nums.length];
            newDp[0] = nums[0];
            newDp[1] = nums[1];
            newDp[2] = Math.max(nums[1], nums[2]);
            for (int i = 3; i < nums.length; i++) {
                newDp[i] = Math.max(newDp[i - 2] + nums[i], newDp[i - 1]);
            }
            return Math.max(dp[nums.length - 2], newDp[nums.length - 1]);
        }
        return dp[nums.length - 1];
    }
}
