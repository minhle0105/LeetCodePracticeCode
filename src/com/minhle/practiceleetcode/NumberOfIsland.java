package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;

public class NumberOfIsland {

    static int[][] visited;
    static final int[] dR = {-1, 1, 0, 0};
    static final int[] dC = {0, 0, -1, 1};

    private static int[] checkIfMapIsFullyVisited() {
        int[] point = {-1,-1};
        for (int i = 0; i < visited.length; i++) {
            for (int j = 0; j < visited[i].length; j++) {
                if (visited[i][j] == 0) {
                    return new int[]{i,j};
                }
            }
        }
        return point;
    }

    public int numIslands(char[][] grid) {
        int numberOfRows = grid.length;
        int numberOfColumns = grid[0].length;
        visited = new int[numberOfRows][numberOfColumns];
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                if (grid[i][j] == '0') {
                    visited[i][j] = 1;
                }
            }
        }
        int count = 0;
        while (true) {
            int[] nextStartPoint = checkIfMapIsFullyVisited();
            if (nextStartPoint[0] == -1) {
                return count;
            }
            bfs(grid, nextStartPoint);
            count++;
        }

    }

    private static void bfs(char[][] grid, int[] startPoint) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startPoint[0]);
        queue.add(startPoint[1]);
        visited[startPoint[0]][startPoint[1]] = 1;
        while (!queue.isEmpty()) {
            int thisX = queue.remove();
            int thisY = queue.remove();
            for (int direction = 0; direction < 4; direction++) {
                int nextX = thisX + dR[direction];
                int nextY = thisY + dC[direction];
                boolean isInBound = nextX >= 0 && nextX < grid.length && nextY >= 0 && nextY < grid[0].length;
                if (isInBound) {
                    if (visited[nextX][nextY] == 0) {
                        queue.add(nextX);
                        queue.add(nextY);
                        visited[nextX][nextY] = 1;
                    }
                }
            }
        }
    }
}
