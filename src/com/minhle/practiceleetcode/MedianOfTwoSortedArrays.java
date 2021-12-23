package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.PriorityQueue;

public class MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        PriorityQueue<Integer> heap = new PriorityQueue<>();
        for (int i : nums1) {
            heap.add(i);
        }
        for (int i : nums2) {
            heap.add(i);
        }
        int n = heap.size();
        int count = 0;
        if (n % 2 != 0) {
            while (count < n/2) {
                heap.remove();
                count++;
            }
            return heap.remove();
        }
        else {
            int a;
            int b;
            while (count <= n/2 - 2) {
                heap.remove();
                count++;
            }
            a = heap.remove();
            b = heap.remove();
            return (double) (a+b) / 2;
        }
    }

    @Test
    void firstTest() {
        int[] nums1 = {1,2};
        int[] nums2 = {2};
        double expected = 2.0000;
        double actual = findMedianSortedArrays(nums1, nums2);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[] nums1 = {1,3};
        int[] nums2 = {2,4};
        double expected = 2.5000;
        double actual = findMedianSortedArrays(nums1, nums2);
        Assertions.assertEquals(expected, actual);
    }
}
