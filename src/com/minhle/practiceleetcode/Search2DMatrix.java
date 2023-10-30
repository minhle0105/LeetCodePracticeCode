package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class Search2DMatrix {

    private int getTheSubArrayIndex(int[][] matrix, int target) {
        int lastColumnIndex = matrix[0].length - 1;
        int firstColumnIndex = 0;
        int[][] first_lastValueOfAllRows = new int[matrix.length][2];
        int counter = 0;
        for (int[] row : matrix) {
            first_lastValueOfAllRows[counter][0] = row[firstColumnIndex];
            first_lastValueOfAllRows[counter++][1] = row[lastColumnIndex];
        }
        for (int i = 0; i < first_lastValueOfAllRows.length; i++) {
            if (first_lastValueOfAllRows[i][0] <= target && target <= first_lastValueOfAllRows[i][1]) {
                return i;
            }
        }
        return -1;
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        int indexOfArrayThatContainsTarget = getTheSubArrayIndex(matrix, target);
        if (indexOfArrayThatContainsTarget == -1) {
            return false;
        }
        int[] subArrayToLookForTarget = matrix[indexOfArrayThatContainsTarget];
        if (subArrayToLookForTarget.length == 1) {
            return subArrayToLookForTarget[0] == target;
        }
        int left = 0;
        int right = subArrayToLookForTarget.length - 1;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (subArrayToLookForTarget[middle] < target) {
                left = middle + 1;
            } else if (subArrayToLookForTarget[middle] > target) {
                right = middle - 1;
            } else {
                return true;
            }
        }
        return false;
    }

    @Test
    void firstTest() {
        int[][] matrix = new int[][]{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 3;
        Assertions.assertTrue(searchMatrix(matrix, target));
    }

    @Test
    void secondTest() {
        int[][] matrix = new int[][]{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 13;
        Assertions.assertFalse(searchMatrix(matrix, target));
    }

    @Test
    void failTest() {
        int[][] matrix = new int[][]{{1},{3}};
        int target = 2;
        Assertions.assertFalse(searchMatrix(matrix, target));
    }

}
