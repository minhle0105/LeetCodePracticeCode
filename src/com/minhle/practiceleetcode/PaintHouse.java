package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class PaintHouse {

    // bottom-up dynamic programming
    int[][] dp;
    public int minCost(int[][] costs) {
        int nRows = costs.length;
        int nCols = costs[0].length;
        dp = new int[nRows][nCols];

        int lastRow = nRows - 1;

        // the last row min cost is cost itself
        System.arraycopy(costs[lastRow], 0, dp[lastRow], 0, nCols);

        for (int r = lastRow - 1; r >= 0; r--) {
            for (int c = 0; c < dp[r].length; c++) {
                if (dp[r][c] == 0) {
                    int minExceptSelf = findMin(dp[r + 1], c);
                    dp[r][c] = costs[r][c] + minExceptSelf;
                }
            }
        }
        int res = findMin(dp[0], dp[0].length);
        return res;
    }

    private int findMin(int[] array, int pivot) {
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < array.length; i++) {
            if (i == pivot) {
                continue;
            }
            res = Math.min(array[i], res);
        }
        return res;
    }

    @Test
    void test1() {
        int[][] costs = {
                {3,5,3},
                {6,17,6}

        };
        int expected = 9;
        int actual = minCost(costs);
        Assertions.assertEquals(expected, actual);
    }
}
