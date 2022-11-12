package com.minhle.practiceleetcode;

import java.util.Comparator;
import java.util.PriorityQueue;

public class FindMedianFromDataStream {
    static class MedianFinder {
        PriorityQueue<Integer> minHeap;
        PriorityQueue<Integer> maxHeap;
        double currentMedian;

        public MedianFinder() {
            minHeap = new PriorityQueue<>();
            maxHeap = new PriorityQueue<>(new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return o2.compareTo(o1);
                }
            });
            currentMedian = 0.0;

        }
        public void addNum(int num) {
            if (!(minHeap.size() == 0) && num > minHeap.peek()) {
                minHeap.add(num);
                while (minHeap.size() > ((maxHeap.size() + minHeap.size())/2)) {
                    maxHeap.add(minHeap.remove());
                }
            }
            else {
                maxHeap.add(num);
                while (maxHeap.size() >= 2 && minHeap.size() < (minHeap.size() + maxHeap.size()) / 2) {
                    minHeap.add(maxHeap.remove());
                }
            }
            updateMedian();
        }

        private void updateMedian() {
            if ((maxHeap.size() + minHeap.size()) % 2 == 0) {
                currentMedian = ( (double) (maxHeap.peek() + minHeap.peek())) / 2;
            }
            else {
                currentMedian = maxHeap.peek();
            }
        }

        public double findMedian() {
            return currentMedian;
        }
    }
}
