package com.minhle.practiceleetcode;

import org.junit.Assert;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class SingleNumberII {
    public int singleNumII(int[] nums) {
        if (nums.length < 1 || nums.length > 3 * Math.pow(10, 4)) {
            return 0;
        }
        HashMap<Integer, Integer> hashmap = new HashMap<>();
        for (int j : nums) {
            if (j < Math.pow(-2, 31) || j > Math.pow(2, 31) - 1) {
                return 0;
            }
            if (!hashmap.containsKey(j)) {
                hashmap.put(j, 1);
            } else {
                if (hashmap.get(j) == 2) {
                    hashmap.remove(j);
                }
                else {
                    hashmap.put(j, hashmap.get(j) + 1);
                }
            }
        }
        return (int) hashmap.keySet().toArray()[0];
    }

    @Test
    void bigIntTest() {
        int expected = 2147483647;
        int[] nums = {43,16,45,89,45,-2147483648,45,2147483646,-2147483647,-2147483648,43,2147483647,-2147483646,-2147483648,89,-2147483646,89,-2147483646,-2147483647,2147483646,-2147483647,16,16,2147483646,43};
        int actual = singleNumII(nums);
        Assertions.assertEquals(expected, actual);
    }
}
