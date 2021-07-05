package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class TwoSum {
      public int[] TwoSumUsingHashMap(int[] nums, int target) {
            HashMap<Integer, Integer> hashmap = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                  hashmap.put(nums[i], i);
            }
            for (int i = 0; i < nums.length; i++) {
                  int diff = target - nums[i];
                  if (hashmap.containsKey(diff) && hashmap.get(diff) != i) {
                        return new int[] {i, hashmap.get(diff)};
                  }
            }
            return null;
      }

      public int[] TwoSumUsingLoops(int[] nums, int target) {
            int[] result = new int[2];
            for (int i = 0; i < nums.length - 1; i++) {
                  int diff = target - nums[i];
                  for (int j = i + 1; j < nums. length; j++) {
                        if (nums[j] == diff) {
                              result[0] = i;
                              result[1] = j;
                        }
                  }
            }
            return result;
      }

      @Test
      void firstTestLoop() {
            int[] expected = {0,1};
            int[] nums = {2,7,11,15};
            int target = 9;
            int[] actual = TwoSumUsingLoops(nums, target);
            Assertions.assertArrayEquals(expected, actual);
      }

      @Test
      void secondTestLoop() {
            int[] expected = {0,1};
            int[] nums = {3,3};
            int target = 6;
            int[] actual = TwoSumUsingLoops(nums, target);
            Assertions.assertArrayEquals(expected, actual);
      }

      @Test
      void lastTestLoop() {
            int[] expected = {1,2};
            int[] nums = {3,2,4};
            int target = 6;
            int[] actual = TwoSumUsingLoops(nums, target);
            Assertions.assertArrayEquals(expected, actual);
      }

      @Test
      void firstTestHash() {
            int[] expected = {0,1};
            int[] nums = {2,7,11,15};
            int target = 9;
            int[] actual = TwoSumUsingHashMap(nums, target);
            Assertions.assertArrayEquals(expected, actual);
      }

      @Test
      void secondTestHash() {
            int[] expected = {0,1};
            int[] nums = {3,3};
            int target = 6;
            int[] actual = TwoSumUsingHashMap(nums, target);
            Assertions.assertArrayEquals(expected, actual);
      }

      @Test
      void lastTestHash() {
            int[] expected = {1,2};
            int[] nums = {3,2,4};
            int target = 6;
            int[] actual = TwoSumUsingHashMap(nums, target);
            Assertions.assertArrayEquals(expected, actual);
      }
}
