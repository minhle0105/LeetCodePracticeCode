package com.minhle.practiceleetcode;

import java.util.*;

class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        List<Double> distances = new ArrayList<>();
        distances.add(getDistance(p1, p2));
        distances.add(getDistance(p1, p3));
        distances.add(getDistance(p1, p4));
        distances.add(getDistance(p2, p3));
        distances.add(getDistance(p2, p4));
        distances.add(getDistance(p3, p4));
        Map<Double, Integer> map = new HashMap<>();
        for (Double distance : distances) {
            if (map.containsKey(distance)) {
                map.put(distance, map.get(distance) + 1);
            }
            else {
                map.put(distance, 1);
            }
        }
        if (map.size() != 2) {
            return false;
        }
        Double[] values = new Double[2];
        int i = 0;
        for (Double key : map.keySet()) {
            values[i++] = key;
        }
        double a = Math.pow(values[0], 2) + Math.pow(values[0], 2);
        double b = Math.pow(values[1], 2);
        double c = Math.pow(values[1], 2) + Math.pow(values[1], 2);
        double d = Math.pow(values[0], 2);

        return Math.abs(a - b) < 0.000001 | Math.abs(c - d) < 0.000001;
    }
    private double getDistance(int[] p1, int[] p2) {
        int x1 = p1[0];
        int y1 = p1[1];
        int x2 = p2[0];
        int y2 = p2[1];
        double a = (y2 - y1) * (y2 - y1);
        double b = (x2 - x1) * (x2 - x1);
        return Math.sqrt(a + b);
    }
}
