package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SpiralMatrixII {
    public int[][] generateMatrix(int n) {
        int count = 0;
        int nCells = n * n;
        int[][] matrix = new int[n][n];
        int[] currentPoint = {0,0};
        matrix[currentPoint[0]][currentPoint[1]] = 1;
        count++;
        while (count < nCells) {
            while (currentPoint[1] < n - 1 && matrix[currentPoint[0]][currentPoint[1] + 1] == 0) {
                currentPoint[1] ++;
                count++;
                matrix[currentPoint[0]][currentPoint[1]] = count;
            }
            while (currentPoint[0] < n - 1 && matrix[currentPoint[0] + 1][currentPoint[1]] == 0) {
                currentPoint[0] ++;
                count++;
                matrix[currentPoint[0]][currentPoint[1]] = count;
            }
            while (currentPoint[1] > 0 && matrix[currentPoint[0]][currentPoint[1] - 1] == 0) {
                currentPoint[1] --;
                count++;
                matrix[currentPoint[0]][currentPoint[1]] = count;
            }
            while (currentPoint[0] > 0 && matrix[currentPoint[0] - 1][currentPoint[1]] == 0) {
                currentPoint[0] --;
                count++;
                matrix[currentPoint[0]][currentPoint[1]] = count;
            }

        }
        return matrix;
    }
    @Test
    void test1 (){
        int n = 3;
        int[][] actual = generateMatrix(n);
        int[][] expected = {
                {1,2,3},
                {8,9,4},
                {7,6,5}
        };
        Assertions.assertArrayEquals(expected, actual);
    }
}
