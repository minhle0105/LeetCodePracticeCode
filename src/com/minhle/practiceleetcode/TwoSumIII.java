package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.Map;

public class TwoSumIII {
    static class TwoSum {

        Map<Integer, Integer> map;

        public TwoSum() {
            map = new HashMap<>();
        }

        public void add(int number) {
            if (map.containsKey(number)) {
                map.put(number, map.get(number) + 1);
            }
            else {
                map.put(number, 1);
            }
        }

        public boolean find(int value) {
            for (Integer key : map.keySet()) {
                int diff = value - key;
                if (map.containsKey(diff)) {
                    if (diff != key | map.get(diff) > 1) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
}
