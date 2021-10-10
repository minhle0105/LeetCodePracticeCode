package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.HashMap;

public class IntersectionsOfTwoArrays {
    private HashMap<Integer, Integer> getFrequency(int[] nums) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i : nums) {
            int addValue = hashMap.containsKey(i) ? hashMap.get(i) + 1 : 1;
            hashMap.put(i, addValue);
        }
        return hashMap;
    }

    public int[] intersection(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hashMap1 = getFrequency(nums1);
        HashMap<Integer, Integer> hashMap2 = getFrequency(nums2);
        int l = nums1.length < nums2.length ? nums1.length : nums2.length;
        int[] result = new int[l];
        int counter = 0;
        for (int i : hashMap1.keySet()) {
            if (hashMap2.containsKey(i)) {
                result[counter++] = i;
            }
            if (counter == l) {
                break;
            }
        }
        result = Arrays.copyOfRange(result, 0, counter);
        return result;
    }

    void bubbleSort(int[] arr) {
        int n = arr.length;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (n - i); j++) {
                if (arr[j - 1] > arr[j]) {
                    //swap elements
                    temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }

            }
        }
    }

    @Test
    void firstTest() {
        int[] expected = {2};
        int[] nums1 = {1, 2, 2, 1};
        int[] nums2 = {2, 2};
        int[] actual = intersection(nums1, nums2);
        bubbleSort(actual);
        bubbleSort(expected);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[] expected = {9, 4};
        int[] nums1 = {4, 9, 5};
        int[] nums2 = {9, 4, 9, 8, 4};
        int[] actual = intersection(nums1, nums2);
        bubbleSort(actual);
        bubbleSort(expected);
        Assertions.assertArrayEquals(expected, actual);
    }

}
