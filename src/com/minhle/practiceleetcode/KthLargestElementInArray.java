package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Comparator;
import java.util.PriorityQueue;

public class KthLargestElementInArray {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2.compareTo(o1);
            }
        });
        for (int i : nums) {
            heap.add(i);
        }
        int result = -1;
        for (int i = 0; i < k - 1; i++) {
            heap.remove();
        }
        return heap.peek();
    }

    @Test
    void firstTest() {
        int[] nums = {3,2,1,5,6,4};
        int k = 2;
        int expected = 5;
        int actual = findKthLargest(nums, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[] nums = {3,2,3,1,2,4,5,5,6};
        int k = 4;
        int expected = 4;
        int actual = findKthLargest(nums, k);
        Assertions.assertEquals(expected, actual);
    }
}
