package com.minhle.practiceleetcode;


import java.util.ArrayList;
import java.util.List;

public class Shift2DGrid {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int count = 0;
        int[][] rotatedGrid = rotate(grid, k, count);
        List<List<Integer>> results = new ArrayList<>();
        for (int[] row : rotatedGrid) {
            List<Integer> result = new ArrayList<>();
            for (int i : row) {
                result.add(i);
            }
            results.add(result);
        }
        return results;
    }

    private int[][] rotate(int[][] grid, int k, int count) {
        if (count == k) {
            return grid;
        }
        int n = grid[0].length;
        int m = grid.length;
        int[][] newGrid = new int[m][n];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (j == n - 1) {
                    if (i == m - 1) {
                        newGrid[0][0] = grid[i][j];
                    }
                    else {
                        newGrid[i + 1][0] = grid[i][n - 1];
                    }

                }
                else {
                    newGrid[i][j + 1] = grid[i][j];
                }
            }
        }
        count++;
        return rotate(newGrid, k, count);
    }
}
