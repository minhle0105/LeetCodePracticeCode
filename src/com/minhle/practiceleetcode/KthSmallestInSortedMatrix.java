package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.PriorityQueue;

public class KthSmallestInSortedMatrix {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        for (int[] row : matrix) {
            for (int i : row) {
                heap.add(i);
            }
        }
        for (int i = 0; i < k - 1; i++) {
            heap.remove();
        }
        return heap.peek();
    }

    @Test
    void firstTest (){
        int[][] nums = {{1,5,9},{10,11,13},{12,13,15}};
        int k = 8;
        int expected = 13;
        int actual = kthSmallest(nums, k);

    }

    @Test
    void secondTest (){
        int[][] nums = {{-5}};
        int k = 1;
        int expected = -5;
        int actual = kthSmallest(nums, k);
        Assertions.assertEquals(expected, actual);
    }
}
