package com.minhle.practiceleetcode;

public class JumpGame {
    public boolean canJump(int[] nums) {
        int dest = nums.length - 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            int reach = i + nums[i];
            if (reach >= dest) {
                dest = i;
            }
        }
        return dest == 0;
    }
}
