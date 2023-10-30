package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LonelyNumber {
    public List<Integer> findLonely(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            }
            else {
                map.put(i, 1);
            }
        }
        List<Integer> results = new ArrayList<>();
        for (int i : map.keySet()) {
            if (map.get(i) == 1 && (!map.containsKey(i + 1) && !map.containsKey(i - 1))) {
                results.add(i);
            }
        }
        return results;
    }


}
