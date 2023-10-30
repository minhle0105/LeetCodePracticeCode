package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ToeplitzMatrix {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int currentColumn = 0;
        int row;
        int column;
        int currentRow = 0;
        while (currentRow < matrix.length) {
            while (currentColumn < matrix[currentRow].length) {
                row = currentRow + 1;
                column = currentColumn + 1;
                while (row < matrix.length && column < matrix[0].length) {

                    if (matrix[currentRow][currentColumn] != matrix[row][column]) {
                        return false;
                    }
                    row++;
                    column++;
                }
                currentColumn++;
            }
            currentRow++;
            currentColumn = 0;
        }

        return true;
    }

    @Test
    void firstTest() {
        int[][] matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
        Assertions.assertTrue(isToeplitzMatrix(matrix));
    }

    @Test
    void secondTest() {
        int[][] matrix = {{1,2},{2,2}};
        Assertions.assertFalse(isToeplitzMatrix(matrix));
    }
    
    @Test
    void failedTest() {
        int[][] matrix = {{41,45},{81,41},{73,81},{47,73},{0,47},{79,76}};
        Assertions.assertFalse(isToeplitzMatrix(matrix));
    }
    // [[11,74,0,93],
    //  [40,11,74,7]]
}
