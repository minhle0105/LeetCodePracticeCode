package com.minhle.practiceleetcode;

public class RangeAddition {
    public int[] getModifiedArray(int length, int[][] updates) {
        int[] res = new int[length];
        for (int[] update : updates) {
            int start = update[0];
            int end = update[1];
            int amount = update[2];
            modify(res, start, end, amount);
        }
        return res;
    }
    private void modify(int[] nums, int start, int end, int amount) {
        for (int i = start; i <= end; i++) {
            nums[i] += amount;
        }
    }
}
