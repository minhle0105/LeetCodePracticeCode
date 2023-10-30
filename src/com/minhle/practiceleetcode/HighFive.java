package com.minhle.practiceleetcode;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class HighFive {
    public int[][] highFive(int[][] items) {
        Map<Integer, PriorityQueue<Integer>> map = new HashMap<>();
        for (int[] item : items) {
            map.put(item[0], new PriorityQueue<>(new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return o2.compareTo(o1);
                }
            }));
        };
        for (int[] item : items) {
            int id = item[0];
            for (int i = 1; i < item.length; i++) {
                map.get(id).add(item[i]);
            }
        }
        Map<Integer, Integer> res = new HashMap<>();
        for (Integer key : map.keySet()) {
            int totalScore = 0;
            for (int i = 0; i < 5; i++) {
                totalScore += map.get(key).remove();
            }
            res.put(key, totalScore / 5);
        }
        int[][] results = new int[res.size()][2];
        int i = 0;
        for (Integer key : res.keySet()) {
            int[] id_score = new int[]{key, res.get(key)};
            results[i] = id_score;
            i++;
        }
        return results;
    }
}
