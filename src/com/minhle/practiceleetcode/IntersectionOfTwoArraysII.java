package com.minhle.practiceleetcode;

import java.util.Arrays;
import java.util.HashMap;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

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
    void firstTest(){
        int[] nums1 = new int[]{61,24,20,58,95,53,17,32,45,85,70,20,83,62,35,89,5,95,12,86,58,77,30,64,46,13,5,92,67,40,20,38,31,18,89,85,7,30,67,34,62,35,47,98,3,41,53,26,66,40,54,44,57,46,70,60,4,63,82,42,65,59,17,98,29,72,1,96,82,66,98,6,92,31,43,81,88,60,10,55,66,82,0,79,11,81};
        int[] nums2 = new int[]{5,25,4,39,57,49,93,79,7,8,49,89,2,7,73,88,45,15,34,92,84,38,85,34,16,6,99,0,2,36,68,52,73,50,77,44,61,48}; // 2 -> 2
        int[] expected = new int[]{5,4,57,79,7,89,88,45,34,92,38,85,6,0,77,44,61};
        int[] actual = intersect(nums1, nums2);
        bubbleSort(expected);
        bubbleSort(actual);
        Assertions.assertArrayEquals(expected, actual);
    }

}
