package com.minhle.practiceleetcode;

import java.util.HashSet;
import java.util.Set;

public class CheckIfEveryRowAndColumnContainsAllNumbers {
    public boolean checkValid(int[][] matrix) {
        int n = matrix.length;
        Set<Integer> set;
        for (int[] row : matrix) {
            set = new HashSet<>();
            for (int r : row) {
                set.add(r);
            }
            if (set.size() != n) {
                return false;
            }
        }
        for (int c = 0; c < n; c++) {
            set = new HashSet<>();
            for (int r = 0; r < n; r++) {
                set.add(matrix[r][c]);
            }
            if (set.size() != n) {
                return false;
            }
        }
        return true;
    }
}
