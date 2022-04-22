package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class RotateImage {
    public void rotate(int[][] matrix) {

        List<int[]> rows = new ArrayList<>();
        for (int i = 0; i < matrix.length; i++) {
            int[] row = new int[matrix.length];
            for (int j = 0; j < matrix.length; j++) {
                row[j] = matrix[i][j];
            }
            rows.add(row);
        }
        int n = matrix.length - 1;
        for (int i = n; i >= 0; i--) {
            int[] cols = rows.get(matrix.length - i - 1);
            for (int j = 0; j <= n; j++) {
                matrix[j][i] = cols[j];
            }
        }

    }
}
