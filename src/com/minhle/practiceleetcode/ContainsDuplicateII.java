package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

public class ContainsDuplicateII {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.get(nums[i]).add(i);
            }
            else {
                map.put(nums[i], new ArrayList<>());
                map.get(nums[i]).add(i);
            }
        }
        List<Integer> duplicateValues = new ArrayList<>();
        for (Integer key : map.keySet()) {
            if (map.get(key).size() > 1) {
                duplicateValues.add(key);
            }
        }
        if (duplicateValues.size() == 0) {
            return false;
        }
        for (Integer value : duplicateValues) {
            List<Integer> indices = map.get(value);
            for (int i = 0; i < indices.size() - 1; i++) {
                if (Math.abs(indices.get(i + 1) - indices.get(i)) <= k) {
                    return true;
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
