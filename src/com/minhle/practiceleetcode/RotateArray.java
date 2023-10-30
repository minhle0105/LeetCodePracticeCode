package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class RotateArray {
    public void rotate(int[] nums, int k) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int value = (i + k) % nums.length;
            hashMap.put(value, nums[i]);
        }
        for (Integer key : hashMap.keySet()) {
            nums[key] = hashMap.get(key);
        }
    }

    public void rotateUsingExtraArray(int[] nums, int k) {
        int[] extra = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            extra[(i+k)%nums.length] = nums[i];
        }
        System.arraycopy(extra, 0, nums, 0, nums.length);
    }

    @Test
    void test1() {
        int[] nums = {1,2,3,4,5,6,7}; // 7 1 2
        int k = 3;
        int[] expected = {5,6,7,1,2,3,4};
        rotate(nums, k);
        Assertions.assertArrayEquals(expected, nums);
    }

    @Test
    void test2() {
        int[] nums = {-1,-100,3,99};
        int k = 2;
        int[] expected = {3,99,-1,-100};
        rotate(nums, k);
        Assertions.assertArrayEquals(expected, nums);
    }

    @Test
    void test3() {
        int[] nums = {1,2,3,4,5,6,7};
        int k = 0;
        int[] expected = {1,2,3,4,5,6,7};
        rotate(nums, k);
        Assertions.assertArrayEquals(expected, nums);
    }
}
