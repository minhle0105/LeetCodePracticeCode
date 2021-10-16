package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class TwoSumII {
    public int[] twoSum(int[] numbers, int target) {
        int[] result = new int[2];
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < numbers.length; i++) {
            hashMap.put(numbers[i], i + 1);
        }
        for (Integer i : hashMap.keySet()) {
            int difference = target - i;
            if (hashMap.containsKey(difference)) {
                result[0] = hashMap.get(i) < hashMap.get(difference) ? hashMap.get(i) : hashMap.get(difference);
                result[1] = result[0] == hashMap.get(i) ? hashMap.get(difference) : hashMap.get(i);
            }
        }
        return result;
    }

    @Test
    void firstTest() {
        int[] nums = {0,0,1,2};
        int target = 0;
        int[] expected = {1,2};
        int[] actual = twoSum(nums, target);
        Assertions.assertArrayEquals(expected, actual);
    }
}
