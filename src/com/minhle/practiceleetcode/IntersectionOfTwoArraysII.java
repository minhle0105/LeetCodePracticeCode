package com.minhle.practiceleetcode;

import java.util.Arrays;
import java.util.HashMap;

public class IntersectionOfTwoArraysII {

    private HashMap<Integer, Integer> getFrequency(int[] nums) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i : nums) {
            int addValue = hashMap.containsKey(i) ? hashMap.get(i) + 1 : 1;
            hashMap.put(i, addValue);
        }
        return hashMap;
    }

    private int updateArray(int[] nums, int pointer, int valueToUpdate, int frequency) {
        int count = 0;
        while (count < frequency) {
            nums[pointer++] = valueToUpdate;
            count++;
        }
        return pointer;
    }

    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hashMap1 = getFrequency(nums1);
        HashMap<Integer, Integer> hashMap2 = getFrequency(nums2);

        int l = nums1.length < nums2.length ? nums1.length : nums2.length;
        int[] result = new int[l];
        int counter = 0;
        for (int i : hashMap1.keySet()) {
            if (hashMap2.containsKey(i)) {
                int frequency = hashMap1.get(i) < hashMap2.get(i) ? hashMap1.get(i) : hashMap2.get(i);
                counter = updateArray(result, counter, i, frequency);
            }
        }
        result = Arrays.copyOfRange(result, 0, counter);
        return result;
    }

}
