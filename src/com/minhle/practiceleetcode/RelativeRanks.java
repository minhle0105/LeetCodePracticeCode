package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class RelativeRanks {
    public String[] findRelativeRanks(int[] score) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < score.length; i++) {
            map.put(score[i], i);
        }
        int count = 1;
        String[] results = new String[score.length];
        int index = 0;
        PriorityQueue<Integer> heap = new PriorityQueue<>((o1, o2) -> o2.compareTo(o1));
        for (int i : score) {
            heap.add(i);
        }
        while (!heap.isEmpty()) {
            int thisRank = heap.remove();
            int indexOfThis = map.get(thisRank);
            if (count == 1) {
                results[indexOfThis] = "Gold Medal";
            }
            else if (count == 2) {
                results[indexOfThis] = "Silver Medal";
            }
            else if (count == 3) {
                results[indexOfThis] = "Bronze Medal";
            }
            else {
                results[indexOfThis] = count + "";
            }
            count++;
        }
        return results;
    }

    @Test
    void test() {
        int[] score = {5,4,3,2,1};
        String[] expected = {"Gold Medal","Silver Medal","Bronze Medal","4","5"};
        String[] actual = findRelativeRanks(score);
        Assertions.assertArrayEquals(expected, actual);

    }
}
