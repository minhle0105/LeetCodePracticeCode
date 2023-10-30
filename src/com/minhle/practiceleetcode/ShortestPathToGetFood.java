package com.minhle.practiceleetcode;
import java.util.*;

public class ShortestPathToGetFood {
    final char BLOCK = 'X';
    final char EMPTY = 'O';
    final char FOOD = '#';
    final int[] dR = {1, -1, 0, 0};
    final int[] dC = {0, 0, 1, -1};

    public int getFood(char[][] grid) {
        int[] startPos = getStart(grid);
        int res = bfs(grid, startPos);
        return res;
    }

    private int bfs(char[][] grid, int[] startPos) {
        Queue<Integer> queue = new LinkedList<>();
        int[][] visited = new int[grid.length][grid[0].length];
        queue.add(startPos[0]);
        queue.add(startPos[1]);
        visited[startPos[0]][startPos[1]] = 1;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == BLOCK) {
                    visited[i][j] = 1;
                }
            }
        }
        int[][] levels = new int[grid.length][grid[0].length];
        while (!queue.isEmpty()) {
            int thisRow = queue.remove();
            int thisCol = queue.remove();
            for (int i = 0; i < 4; i++) {
                int nextRow = thisRow + dR[i];
                int nextCol = thisCol + dC[i];
                boolean isInBound = nextRow >= 0 && nextRow < grid.length && nextCol >= 0 && nextCol < grid[0].length;
                if (isInBound) {
                    if (visited[nextRow][nextCol] == 0) {
                        visited[nextRow][nextCol] = 1;
                        queue.add(nextRow);
                        queue.add(nextCol);
                        levels[nextRow][nextCol] = levels[thisRow][thisCol] + 1;
                    }
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < levels.length; i++) {
            for (int j = 0; j < levels[i].length; j++) {
                boolean hasFood = grid[i][j] == FOOD;
                if (hasFood) {
                    boolean foodCanBeReached = visited[i][j] == 1;
                    if (foodCanBeReached) {
                        res = Math.min(res, levels[i][j]);
                    }
                }
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
    private int[] getStart(char[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '*') {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{-1, -1};
    }
}
