package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class KthMissingPositiveInteger {
    public int findKthPositive(int[] arr, int k) {
        int countMissing = 0;
        int posInt = 1;
        List<Integer> missing = new ArrayList<>();
        for (int i = 1; i < arr[0]; i++) {
            missing.add(i);
        }
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] + 1 != arr[i + 1]) {
                for (int j = arr[i] + 1; j < arr[i + 1]; j++) {
                    missing.add(j);
                }
                if (missing.size() >= k) {
                    break;
                }
            }
        }
        int nextValue = arr[arr.length - 1] + 1;
        while (missing.size() < k) {
            missing.add(nextValue);
            nextValue++;
        }
        return missing.get(k - 1);
    }

    @Test
    void test1() {
       int[] arr = {2,3,4,7,11};
       int k = 5;
       int expected = 9;
       int actual = findKthPositive(arr, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] arr = {1,2,3,4};
        int k = 2;
        int expected = 6;
        int actual = findKthPositive(arr, k);
        Assertions.assertEquals(expected, actual);
    }
}
