package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class MajorityElement {
    public int majorityElement(int[] nums) {
        int length = nums.length / 2;
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i : nums) {
            if (hashMap.containsKey(i)) {
                hashMap.put(i, hashMap.get(i) + 1);
            }
            else {
                hashMap.put(i, 1);
            }
        }
        for (Integer key : hashMap.keySet()) {
            if (hashMap.get(key) > length) {
                return key;
            }
        }
        return -1;
    }

    @Test
    void firstTest() {
        int[] nums = {2,2,1,1,1,2,2};
        int expected = 2;
        int actual = majorityElement(nums);
        Assertions.assertEquals(expected, actual);
    }
}
