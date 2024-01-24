package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Comparator;
import java.util.PriorityQueue;

public class LargestEvenSum {
    private int getEvenSum(int[] arr) {
        int evenSum = 0;
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(o2, o1);
            }
        });
        for (int a : arr) {
            if (a % 2 == 0) {
                evenSum += a;
            }
            else {
                maxHeap.add(a);
            }
        }
        while (maxHeap.size() > 2 && maxHeap.peek() > 0) {
            evenSum += maxHeap.remove();
            evenSum += maxHeap.remove();
        }
        return evenSum;
    }

    @Test
    void test1() {
        int[] arr = {2,3,6,-5,10,1,1};
        Assertions.assertEquals(22, getEvenSum(arr));
    }
}
