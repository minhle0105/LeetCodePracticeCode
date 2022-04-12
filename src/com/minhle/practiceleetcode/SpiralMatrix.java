package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SpiralMatrix {
    public List<Integer> spiralOrder(int[][] matrix) {
        int nRow = matrix.length;
        int nCol = matrix[0].length;
        int[][] visited = new int[nRow][nCol];
        int count = 0;
        int nCells = nRow * nCol;
        List<Integer> orders = new ArrayList<>();
        orders.add(matrix[0][0]);
        int[] currentPoint = {0,0};
        visited[0][0] = 1;
        count++;
        while (count < nCells) {
            while (currentPoint[1] < nCol - 1 && visited[currentPoint[0]][currentPoint[1] + 1] == 0) {
                currentPoint[1] ++;
                orders.add(matrix[currentPoint[0]][currentPoint[1]]);
                count++;
                visited[currentPoint[0]][currentPoint[1]] = 1;
            }
            while (currentPoint[0] < nRow - 1 && visited[currentPoint[0] + 1][currentPoint[1]] == 0) {
                currentPoint[0] ++;
                orders.add(matrix[currentPoint[0]][currentPoint[1]]);
                count++;
                visited[currentPoint[0]][currentPoint[1]] = 1;
            }
            while (currentPoint[1] > 0 && visited[currentPoint[0]][currentPoint[1] - 1] == 0) {
                currentPoint[1] --;
                orders.add(matrix[currentPoint[0]][currentPoint[1]]);
                count++;
                visited[currentPoint[0]][currentPoint[1]] = 1;
            }
            while (currentPoint[0] > 0 && visited[currentPoint[0] - 1][currentPoint[1]] == 0) {
                currentPoint[0] --;
                orders.add(matrix[currentPoint[0]][currentPoint[1]]);
                count++;
                visited[currentPoint[0]][currentPoint[1]] = 1;
            }

        }
        return orders;
    }

    @Test
    void test1() {
        int[][] matrix = {
                {1,2,3},
                {4,5,6},
                {7,8,9}
        };
        List<Integer> actual = spiralOrder(matrix);
        List<Integer> expected = Arrays.asList(1,2,3,6,9,8,7,4,5);
        Assertions.assertEquals(actual, expected);
    }

    @Test
    void test2() {
        int[][] matrix = {
                {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12}
        };
        List<Integer> actual = spiralOrder(matrix);
        List<Integer> expected = Arrays.asList(1,2,3,4,8,12,11,10,9,5,6,7);
        Assertions.assertEquals(actual, expected);
    }
}
