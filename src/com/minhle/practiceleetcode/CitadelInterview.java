package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class CitadelInterview {
    private int getMostVisited(int n, List<Integer> sprints) {
        List<Integer> phases = new ArrayList<>();
        for (int i = 0; i < sprints.size() - 1; i++) {
            int start = sprints.get(i);
            int end = sprints.get(i + 1);
            if (start < end) {
                for (int a = start; a <= end; a++) {
                    phases.add(a);
                }
            }
            else {
                for (int a = start; a >= end; a--) {
                    phases.add(a);
                }
            }
        }
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (Integer i : phases) {
            if (hashMap.containsKey(i)) {
                hashMap.put(i, hashMap.get(i) + 1);
            }
            else {
                hashMap.put(i,1);
            }
        }
        int maxResult = -1;
        for (Integer value : hashMap.values()) {
            if (value >= maxResult) {
                maxResult = value;
            }
        }
        List<Integer> results = new ArrayList<>();
        for (Integer key : hashMap.keySet()) {
            if (hashMap.get(key) == maxResult) {
                results.add(key);
            }
        }
        if (results.size() == 1) {
            return results.get(0);
        }
        else {
            int smallest = results.get(0);
            for (int i = 1; i < results.size(); i++) {
                if (results.get(i) < smallest) {
                    smallest = results.get(i);
                }
            }
            return smallest;
        }
    }

    @Test
    void firstTest() {
        int n = 5;
        List<Integer> sprints = new ArrayList<>(Arrays.asList(2,4,1,3));
        int expected = 2;
        int actual = getMostVisited(n, sprints);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int n = 10;
        List<Integer> sprints = new ArrayList<>(Arrays.asList(4,1,5,10,3));
        int expected = 3;
        int actual = getMostVisited(n, sprints);
        Assertions.assertEquals(expected, actual);
    }
}
