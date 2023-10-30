package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MatrixZeroes {
    public void setZeroes(int[][] matrix) {
        List<Integer> rowsWithZeroes = new ArrayList<>();
        List<Integer> columnsWithZeroes = new ArrayList<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 0) {
                    if (!rowsWithZeroes.contains(i)) {
                        rowsWithZeroes.add(i);
                    }
                    if (!columnsWithZeroes.contains(j)) {
                        columnsWithZeroes.add(j);
                    }
                }
            }
        }

        for (Integer row : rowsWithZeroes) {
            Arrays.fill(matrix[row], 0);
        }

        for (Integer column : columnsWithZeroes) {
            for (int[] row : matrix) {
                row[column] = 0;
            }
        }
    }

    @Test
    void firstTest() {
        int[][] matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        setZeroes(matrix);
        int[][] expected = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
        Assertions.assertArrayEquals(expected, matrix);
    }

    @Test
    void secondTest() {
        int[][] matrix = {{1,1,1},{1,0,1},{1,1,1}};
        setZeroes(matrix);
        int[][] expected = {{1,0,1},{0,0,0},{1,0,1}};
        Assertions.assertArrayEquals(expected, matrix);
    }

}
