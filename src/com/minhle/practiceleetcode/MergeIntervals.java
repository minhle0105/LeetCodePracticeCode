package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class MergeIntervals {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> inputs = new ArrayList<>(Arrays.asList(intervals));
        List<int[]> outputs = merge(inputs);
        return outputs.toArray(new int[outputs.size()][2]);
    }

    static List<int[]> merge(List<int[]> inputs) {
        LinkedList<int[]> merged = new LinkedList<>();
        merged.add(inputs.get(0));
        for (int i = 1; i < inputs.size(); i++) {
            int[] firstEvent = merged.get(merged.size() - 1);
            int[] secondEvent = inputs.get(i);
            if (firstEvent[1] >= secondEvent[0]) {
                int[] mergedEvent = new int[]{firstEvent[0], Math.max(secondEvent[1], firstEvent[1])};
                merged.removeLast();
                merged.add(mergedEvent);
            }
            else {
                merged.add(secondEvent);
            }
        }
        return merged;
    }

    @Test
    void test1() {
        int[][] intervals = {{1,3},{2,6},{8,10},{15,18}};
        int[][] expected = {{1,6},{8,10},{15,18}};
        int[][] actual = merge(intervals);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void test2() {
        int[][] intervals = {{1,4}, {4,5}};
        int[][] expected = {{1,5}};
        int[][] actual = merge(intervals);
        Assertions.assertArrayEquals(expected, actual);
    }
}
