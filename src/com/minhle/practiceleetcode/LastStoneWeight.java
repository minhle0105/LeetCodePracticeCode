package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.PriorityQueue;

public class LastStoneWeight {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> heap = new PriorityQueue<>(((o1, o2) -> o2.compareTo(o1)));
        for (int stone : stones) {
            heap.add(stone);
        }
        while (heap.size() >= 2) {
            int a = heap.remove();
            int b = heap.remove();
            if (a != b) {
                heap.add(a - b);
            }
        }
        return heap.size() == 1 ? heap.peek() : 0;
    }

    @Test
    void test1() {
        int[] stones = {1,3};
        int expected = 2;
        int actual = lastStoneWeight(stones);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] stones = {2,7,4,1,8,1};
        int expected = 1;
        int actual = lastStoneWeight(stones);
        Assertions.assertEquals(expected, actual);
    }
}
