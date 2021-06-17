package com.minhle.practiceleetcode;

import java.util.HashMap;

public class SingleNumber {
      public int singleNum(int[] nums) {
            if (nums.length < 1 || nums.length > 3 * Math.pow(10, 4)) {
                  return 0;
            }
            HashMap<Integer, Integer> hashmap = new HashMap<>();
            for (int j : nums) {
                  if (j < -3 * Math.pow(10, 4) || j > 3 * Math.pow(10, 4)) {
                        return 0;
                  }
                  if (!hashmap.containsKey(j)) {
                        hashmap.put(j, 1);
                  } else {
                        hashmap.put(j, hashmap.get(j) + 1);
                  }
            }
            for (int num : nums) {
                  if (hashmap.get(num) == 1) {
                        return num;
                  }
            }
            return 0;
      }
}
