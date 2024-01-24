package com.minhle.practiceleetcode;

import java.util.*;

public class DegreeOfAnArray {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
        }
        int maxFreq = 0;
        List<Integer> maxKeys = new ArrayList<>();
        for (Integer key : map.keySet()) {
            if (map.get(key) > maxFreq) {
                maxFreq = map.get(key);
            }
        }
        for (Integer key : map.keySet()) {
            if (map.get(key) == maxFreq) {
                maxKeys.add(key);
            }
        }

        Map<Integer, List<Integer>> maxKeyIndices = new HashMap<>();
        for (Integer maxKey : maxKeys) {
            maxKeyIndices.put(maxKey, new ArrayList<>());
        }
        for (Integer key : maxKeyIndices.keySet()) {
            int firstTimeAppear = 0;
            int lastTimeAppear = 0;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == key) {
                    firstTimeAppear = i;
                    break;
                }
            }
            for (int i = nums.length - 1; i >= 0; i--) {
                if (nums[i] == key) {
                    lastTimeAppear = i;
                    break;
                }
            }
            maxKeyIndices.get(key).add(firstTimeAppear);
            maxKeyIndices.get(key).add(lastTimeAppear);
        }
        int res = 0;
        for (Integer key : maxKeyIndices.keySet()) {
            res = maxKeyIndices.get(key).get(1) - maxKeyIndices.get(key).get(0) + 1;
            break;
        }
        for (Integer key : maxKeyIndices.keySet()) {
            int diff = maxKeyIndices.get(key).get(1) - maxKeyIndices.get(key).get(0) + 1;
            res = Math.min(diff, res);
        }
        return res;

    }
}
