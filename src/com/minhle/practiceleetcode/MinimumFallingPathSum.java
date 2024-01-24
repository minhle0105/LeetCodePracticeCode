package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class MinimumFallingPathSum {
    int[][] dp;
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        dp = new int[n][n];
        System.arraycopy(matrix[n - 1], 0, dp[n - 1], 0, n);
        for (int r = n - 2; r >= 0; r--) {
            for (int c = 0; c < n; c++) {
                int x = Integer.MAX_VALUE;
                int y = Integer.MAX_VALUE;
                int z = Integer.MAX_VALUE;
                try {
                    x = dp[r + 1][c - 1];
                }
                catch (Exception ignored) {

                }
                try {
                    y = dp[r + 1][c];
                }
                catch (Exception ignored) {

                }
                try {
                    z = dp[r + 1][c + 1];
                }
                catch (Exception ignored) {

                }
                dp[r][c] = matrix[r][c] + Math.min(x, Math.min(y, z));
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            res = Math.min(res, dp[0][i]);
        }
        return res;
    }


    @Test
    void test1() {
        int[][] matrix = {
                {-19, 57},
                {-40, -5}
        };
        Assertions.assertEquals(-59, minFallingPathSum(matrix));
    }

    @Test
    void test2() {
        int[][] matrix = {
                {2,1,3},
                {6,5,4},
                {7,8,9}
        };
        Assertions.assertEquals(13, minFallingPathSum(matrix));
    }
}
