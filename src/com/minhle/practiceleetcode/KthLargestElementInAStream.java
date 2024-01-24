package com.minhle.practiceleetcode;

import java.util.PriorityQueue;

public class KthLargestElementInAStream {
    static class KthLargest {
        int k;
        PriorityQueue<Integer> heap;

        public KthLargest(int k, int[] nums) {
            this.k = k;
            heap = new PriorityQueue<>();
            for (int num : nums) {
                heap.add(num);
            }
            while (heap.size() > k) {
                heap.remove();
            }
        }

        public int add(int val) {
            heap.add(val);
            while (heap.size() > k) {
                heap.remove();
            }
            return heap.peek();
        }
    }
}
