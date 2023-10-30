package com.minhle.practiceleetcode;

public class RangeSumQuery2D {
    static class NumMatrix {
        private int[][] cached;

        public NumMatrix(int[][] matrix) {
            int nRows = matrix.length;
            int nCols = matrix[0].length;
            this.cached = new int[nRows + 1][nCols + 1];
            for (int row = 1; row <= nRows; row++) {
                for (int col = 1; col <= nCols; col++) {
                    this.cached[row][col] = this.cached[row - 1][col]
                            + this.cached[row][col - 1]
                            + matrix[row - 1][col - 1]
                            - this.cached[row - 1][col - 1];
                }
            }
        }

        public int sumRegion(int row1, int col1, int row2, int col2) {
            int totalArea = this.cached[row2 + 1][col2 + 1];
            int minusAreaHorizontal = this.cached[row1][col2 + 1];
            int minusAreaVertical = this.cached[row2 + 1][col1];
            int overlappedArea = this.cached[row1][col1];
            int sum = totalArea - minusAreaHorizontal - minusAreaVertical + overlappedArea;
            return sum;
        }
    }
}
