package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ReshapeTheMatrix {

    private int getTotalElementInTheMatrix(int[][] mat) {
        int originalMatrixSize = 0;
        for (int[] row : mat) {
            for (int number : row) {
                originalMatrixSize++;
            }
        }
        return originalMatrixSize;
    }

    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int originalMatrixSize = getTotalElementInTheMatrix(mat);

        if (r * c != originalMatrixSize) {
            return mat;
        }
        int originalColumnLength = mat[0].length;
        int currentRow = 0;
        int currentColumn = 0;
        int[][] result = new int[r][c];
        for (int row = 0; row < r; row++) {
            for (int column = 0; column < c; column++) {
                result[row][column] = mat[currentRow][currentColumn++];
                if (currentColumn == originalColumnLength) {
                    currentRow++;
                    currentColumn = 0;
                }
            }
        }
        return result;
    }

    @Test
    void firstTest() {
        int[][] mat = new int[][]{{1,2}, {3,4}};
        int r = 1;
        int c = 4;
        int[][] expected = new int[][]{{1,2,3,4}};
        int[][] actual = matrixReshape(mat, r, c);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[][] mat = new int[][]{{1,2}, {3,4}};
        int r = 2;
        int c = 4;
        int[][] expected = new int[][]{{1,2},{3,4}};
        int[][] actual = matrixReshape(mat, r, c);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void failTest() {
        int[][] mat = new int[][]{{1,2, 3,4}};
        int r = 2;
        int c = 2;
        int[][] expected = new int[][]{{1,2},{3,4}};
        int[][] actual = matrixReshape(mat, r, c);
        Assertions.assertArrayEquals(expected, actual);
    }
}
