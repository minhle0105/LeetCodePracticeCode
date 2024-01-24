package com.minhle.practiceleetcode;

public class MaxConsecutiveOnes {
    public int findMaxConsecutiveOnes(int[] nums) {
        int r = 0;
        int res = Integer.MIN_VALUE;
        while (r < nums.length) {
            StringBuilder s = new StringBuilder(nums[r] + "");
            int l = r + 1;
            while (l < nums.length && nums[r] == nums[l]) {
                s.append(nums[l]);
                l++;
            }
            if (s.charAt(0) == '1') {
                res = Math.max(res, s.length());
            }
            r = l;
        }
        return res ==  Integer.MIN_VALUE ? 0 : res;
    }
}
