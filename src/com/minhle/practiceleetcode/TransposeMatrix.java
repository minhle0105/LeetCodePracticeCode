package com.minhle.practiceleetcode;

public class TransposeMatrix {
    public int[][] transpose(int[][] matrix) {
        int[][] transposedMatrix = new int[matrix[0].length][matrix.length];
        int column = 0;
        while (column < matrix.length) {
            copyMatrix(matrix[column], transposedMatrix, column);
            column++;
        }
        return transposedMatrix;
    }
    private void copyMatrix(int[] rowToCopy, int[][] results, int column) {
        int row = 0;
        for (int num : rowToCopy) {
            results[row][column] = num;
            row++;
        }
    }
}
