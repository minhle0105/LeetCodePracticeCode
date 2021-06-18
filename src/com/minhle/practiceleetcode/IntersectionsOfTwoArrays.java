package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.HashMap;

public class IntersectionsOfTwoArrays {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i : nums1) {
            if (!hashMap.containsKey(i)) {
                hashMap.put(i, 1);
            }
            else {
                hashMap.put(i, hashMap.get(i) + 1);
            }
        }
        ArrayList<Integer> results = new ArrayList<>();
        for (int i : nums2) {
            if (hashMap.containsKey(i) && (!results.contains(i))) {
                results.add(i);
            }
        }
        int[] finalResult = new int[results.size()];
        for (int i = 0; i < finalResult.length; i++) {
            finalResult[i] = results.get(i);
        }
        return finalResult;
    }

    @Test
    void firstTest() {
        int[] expected = {2};
        int[] nums1 = {1,2,2,1};
        int[] nums2 = {2,2};
        int[] actual = intersection(nums1, nums2);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[] expected = {9,4};
        int[] nums1 = {4,9,5};
        int[] nums2 = {9,4,9,8,4};
        int[] actual = intersection(nums1, nums2);
        Assertions.assertArrayEquals(expected, actual);
    }

}
