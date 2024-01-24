package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class InsertIntervals {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> list = new ArrayList<>();
        int[][] t = new int[intervals.length + 1][2];
        for (int i = 0; i < intervals.length; i++) {
            t[i] = intervals[i];
        }
        t[t.length - 1] = newInterval;
        Arrays.sort(t, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });
        int i = 0;
        intervals = new int[intervals.length + 1][2];
        for (int[] event : t) {
            intervals[i] = new int[]{event[0], event[1]};
            i++;
        }
        list.add(intervals[0]);
        int currentEventIndex = 1;
        while (currentEventIndex < intervals.length) {
            int[] mostRecentEvent = list.get(list.size() - 1);
            int[] currentEvent = intervals[currentEventIndex];
            if (isOverlapped(mostRecentEvent, currentEvent)) {
                int[] merged = mergeEvent(mostRecentEvent, currentEvent);
                list.remove(list.size() - 1);
                list.add(merged);
            }
            else {
                list.add(currentEvent);
            }
            currentEventIndex++;
        }
        int[][] res = convertList(list);
        return res;
    }

    private int[][] convertList(List<int[]> list) {
        int[][] res = new int[list.size()][2];
        for (int i = 0; i < list.size(); i++) {
            res[i] = list.get(i);
        }
        return res;
    }

    private int[] mergeEvent (int[] event1, int[] event2) {
        int newStart = Math.min(event1[0], event2[0]);
        int newFinish = Math.max(event1[1], event2[1]);
        return new int[]{newStart, newFinish};
    }

    private boolean isOverlapped(int[] interval1, int[] interval2) {
        return (!(interval1[0] > interval2[1]) && !(interval2[0] > interval1[1]));
    }

    @Test
    void testOverlapped1() {
        int[] interval1 = {1,2};
        int[] interval2 = {4,8};
        Assertions.assertFalse(isOverlapped(interval1, interval2));
    }

    @Test
    void testOverlapped2() {
        int[] interval1 = {3,5};
        int[] interval2 = {4,8};
        Assertions.assertTrue(isOverlapped(interval1, interval2));
    }

    @Test
    void testReal1() {
        int[][] intervals = {{1,3}, {6,9}};
        int[] newInterval = {2,5};
        insert(intervals, newInterval);
    }

    @Test
    void testReal2() {
        int[][] intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
        int[] newInterval = {4,8};
        insert(intervals, newInterval);
    }

    @Test
    void testReal3() {
        int[][] intervals = {{1,5}};
        int[] newInterval = {6,8};
        insert(intervals, newInterval);
    }
}
