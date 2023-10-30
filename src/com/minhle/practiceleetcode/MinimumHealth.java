package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class MinimumHealth {
    private int getMinimumHealth(int[] initialPlayers, int[] nextPlayers, int rank) {
        int res = 0;
        int next = 0;
        LinkedList<Integer> currentPlayers = new LinkedList<>();
        for (int player : initialPlayers) {
            currentPlayers.add(player);
        }
        int currentMinHeapLength = initialPlayers.length - rank + 1;
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(o2, o1);
            }
        });
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(o1, o2);
            }
        });
        maxHeap.addAll(currentPlayers);
        while (!maxHeap.isEmpty() && maxHeap.size() > currentMinHeapLength) {
            minHeap.add(maxHeap.remove());
        }
        while (true) {
            try {
                int size = maxHeap.size() + minHeap.size() - rank + 1;
                res += maxHeap.peek();
                if (nextPlayers[next] < minHeap.peek()) {
                    maxHeap.add(nextPlayers[next++]);
                }
                else {
                    while (!minHeap.isEmpty() && maxHeap.size() < size + 1) {
                        maxHeap.add(minHeap.remove());
                    }
                    minHeap.add(nextPlayers[next++]);
                }
            }
            catch (IndexOutOfBoundsException e) {
                break;
            }
        }
        return res;
    }

    @Test
    void test1() {
        int[] initialPlayers = {1,2};
        int[] nextPlayers = {3,4};
        int k = 2;
        Assertions.assertEquals(6, getMinimumHealth(initialPlayers, nextPlayers, k));
    }

    @Test
    void test2() {
        int[] initialPlayers = {1,2,3};
        int[] nextPlayers = {6,8,4};
        int k = 3;
        Assertions.assertEquals(10, getMinimumHealth(initialPlayers, nextPlayers, k));
    }
}
