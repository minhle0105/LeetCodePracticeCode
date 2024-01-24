package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;


public class MergeSortedArrays {
    public static void solution(int[] nums1, int m, int[] nums2, int n) {
        int pointer1 = m - 1;
        int pointer2 = n - 1;
        int replacingPointer = nums1.length - 1;
        while (pointer1 >= 0 && pointer2 >= 0) {
            if (nums1[pointer1] < nums2[pointer2]) {
                nums1[replacingPointer--] = nums2[pointer2--];
            } else {
                nums1[replacingPointer--] = nums1[pointer1--];
            }
        }
        if (pointer1 < 0) {
            while (pointer2 >= 0) {
                nums1[replacingPointer--] = nums2[pointer2--];
            }

        } else {
            while (pointer1 >= 0) {
                nums1[replacingPointer--] = nums1[pointer1--];
            }
        }
    }

    @Test
    void firstTest() {
        int[] nums1 = new int[]{1, 2, 3, 0, 0, 0};
        int[] nums2 = new int[]{2, 5, 6};
        int m = 3;
        int n = 3;
        int[] result = new int[]{1, 2, 2, 3, 5, 6};
        solution(nums1, m, nums2, n);
        Assertions.assertArrayEquals(nums1, result);
    }

    @Test
    void secondTest() {
        int[] nums1 = new int[]{1};
        int[] nums2 = new int[]{};
        int m = 1;
        int n = 0;
        int[] result = new int[]{1};
        solution(nums1, m, nums2, n);
        Assertions.assertArrayEquals(nums1, result);
    }

    @Test
    void thirdTest() {
        int[] nums1 = new int[]{0};
        int[] nums2 = new int[]{1};
        int m = 0;
        int n = 1;
        int[] result = new int[]{1};
        solution(nums1, m, nums2, n);
        Assertions.assertArrayEquals(nums1, result);
    }

    @Test
    void failCase() {
        int[] nums1 = new int[]{4, 5, 6, 0, 0, 0};
        int[] nums2 = new int[]{1, 2, 3};
        int m = 3;
        int n = 3;
        int[] result = new int[]{1, 2, 3, 4, 5, 6};
        solution(nums1, m, nums2, n);
        Assertions.assertArrayEquals(nums1, result);
    }

}
