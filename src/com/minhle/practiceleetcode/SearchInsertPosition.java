package com.minhle.practiceleetcode;

public class SearchInsertPosition {
    public int searchInsert(int[] nums, int target) {
        int index = 0;
        int closetIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                index = i;
                return index;
            }
            if (nums[i] < target) {
                closetIndex++;
            }
        }
        return closetIndex;
    }
}
