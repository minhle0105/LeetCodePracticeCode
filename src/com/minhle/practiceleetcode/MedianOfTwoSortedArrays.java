package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Comparator;
import java.util.PriorityQueue;

public class MedianOfTwoSortedArrays {

    private static int[] mergeArraysIntoOne(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length + nums2.length];
        int count = 0;
        for (int j : nums1) {
            result[count++] = j;
        }
        for (int i : nums2) {
            result[count++] = i;
        }
        return result;
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        PriorityQueue<Integer> firstHalfHeap = new PriorityQueue<>();
        PriorityQueue<Integer> secondHalfHeap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2.compareTo(o1);
            }
        });
        int[] mergedArray = mergeArraysIntoOne(nums1, nums2);
        for (int i : mergedArray) {
            if (!firstHalfHeap.isEmpty() && i > firstHalfHeap.peek()) {
                firstHalfHeap.add(i);
                if (firstHalfHeap.size() > (firstHalfHeap.size() + secondHalfHeap.size()) / 2) {
                    secondHalfHeap.add(firstHalfHeap.remove());
                }
            }
            else {
                secondHalfHeap.add(i);
                if (secondHalfHeap.size() >= 2 && firstHalfHeap.size() < (firstHalfHeap.size() + secondHalfHeap.size()) / 2) {
                    firstHalfHeap.add(secondHalfHeap.remove());
                }
            }
        }
        if ((firstHalfHeap.size() + secondHalfHeap.size()) % 2 == 0) {
            return (double) (firstHalfHeap.remove() + secondHalfHeap.remove())/2;
        }
        else {
            return firstHalfHeap.size() > secondHalfHeap.size() ? firstHalfHeap.remove() : secondHalfHeap.remove();
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

    @Test
    void failedTest() {
        int[] nums1 = {1,3};
        int[] nums2 = {2};
        double expected = 2.00000;
        double actual = findMedianSortedArrays(nums1, nums2);
        Assertions.assertEquals(expected, actual);
    }
}
