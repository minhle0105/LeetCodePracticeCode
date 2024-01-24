package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class Triangle {
    public int minimumTotal(List<List<Integer>> triangle) {
        List<Integer> minSum = new ArrayList<>();
        for (int i = 0; i <= triangle.size(); i++) {
            minSum.add(0);
        }
        for (int row = triangle.size() - 1; row >= 0; row --) {
            for (int column = 0; column < triangle.get(row).size(); column ++) {
                int n = triangle.get(row).get(column);
                minSum.set(column, n + Math.min(minSum.get(column), minSum.get(column + 1)));
            }
        }
        return minSum.get(0);
    }
}
