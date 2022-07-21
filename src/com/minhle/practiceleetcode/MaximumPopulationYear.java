package com.minhle.practiceleetcode;

import java.util.LinkedHashMap;
import java.util.Map;

public class MaximumPopulationYear {
    public int maximumPopulation(int[][] logs) {
        Map<Integer, Integer> map = new LinkedHashMap<>();
        for (int i = 1950; i <= 2050; i++) {
            map.put(i, 0);
        }
        for (int[] log : logs) {
            int birth = log[0];
            int death = log[1];
            for (int year = birth; year < death; year++) {
                map.put(year, map.get(year) + 1);
            }
        }
        int maxPopulation = 0;
        for (Integer year : map.keySet()) {
            maxPopulation = Math.max(map.get(year), maxPopulation);
        }
        for (Integer year : map.keySet()) {
            if (map.get(year) == maxPopulation) {
                return year;
            }
        }
        return -1;
    }
}
