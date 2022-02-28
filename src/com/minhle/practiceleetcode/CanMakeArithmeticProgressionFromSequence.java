package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class CanMakeArithmeticProgressionFromSequence {
    public boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.length; i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }

    @Test
    void test1() {
        int[] arr = {3,5,1};
        Assertions.assertTrue(canMakeArithmeticProgression(arr));
    }

    @Test
    void test2() {
        int[] arr = {1,2,4};
        Assertions.assertFalse(canMakeArithmeticProgression(arr));
    }
}
