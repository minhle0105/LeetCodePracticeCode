package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.HashMap;

import static org.junit.jupiter.api.Assertions.*;

public class ContainsDuplicateII {
    private boolean checkSubCondition(int i, int j, int k) {
        return Math.abs(i-j) <= k;
    }
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    if (checkSubCondition(i, j, k)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    @Test
    void firstTest() {
        int[] nums = new int[]{1,2,3,1};
        int k = 3;
        assertTrue(containsNearbyDuplicate(nums, k));
    }

    @Test
    void secondTest() {
        int[] nums = new int[]{1,0,1,1};
        int k = 1;
        assertTrue(containsNearbyDuplicate(nums, k));
    }

    @Test
    void thirdTest() {
        int[] nums = new int[]{1,2,3,1,2,3};
        int k = 2;
        assertFalse(containsNearbyDuplicate(nums, k));
    }


}
