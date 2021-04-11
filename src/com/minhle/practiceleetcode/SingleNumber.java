package com.minhle.practiceleetcode;

import java.util.HashMap;

public class SingleNumber {
      public int singleNum(int[] nums) {
            if (nums.length < 1 || nums.length > 3 * Math.pow(10, 4)) {
                  return 0;
            }
            HashMap<Integer, Integer> hashmap = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                  if (nums[i] < -3 * Math.pow(10,4) || nums[i] > 3 * Math.pow(10,4)) {
                        return 0;
                  }
                  if (!hashmap.containsKey(nums[i])) {
                        hashmap.put(nums[i], 1);
                  }
                  else {
                        hashmap.put(nums[i], hashmap.get(nums[i]) + 1);
                  }
            }
            for (int i = 0; i < nums.length; i++) {
                  if (hashmap.get(nums[i]) == 1) {
                        return nums[i];
                  }
            }
            return 0;
      }
}
