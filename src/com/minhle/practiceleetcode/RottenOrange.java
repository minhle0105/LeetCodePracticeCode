package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.Queue;

public class RottenOrange {

    static final int[] dR = {-1, 1, 0, 0};
    static final int[] dC = {0, 0, -1, 1};

    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] visited = new int[m][n];
        int[][] distance = new int[m][n];
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    visited[i][j] = 1;
                }
                if (grid[i][j] == 2) {
                    queue.add(i);
                    queue.add(j);
                    visited[i][j] = 1;
                }
                if (grid[i][j] == 1) {
                    distance[i][j] = Integer.MIN_VALUE;
                }
            }
        }
        return bfs(queue, visited, distance, m, n);
    }

    private int bfs(Queue<Integer> queue, int[][] visited, int[][] distance, int m, int n) {
        while (!queue.isEmpty()) {
            int thisX = queue.remove();
            int thisY = queue.remove();
            for (int direction = 0; direction < 4; direction++) {
                int nextX = thisX + dR[direction];
                int nextY = thisY + dC[direction];
                boolean isInBound = nextX >= 0 && nextX < m && nextY >= 0 && nextY < n;
                if (isInBound) {
                    if (visited[nextX][nextY] == 0) {
                        if (distance[thisX][thisY] + 1 > distance[nextX][nextY] && visited[nextX][nextY] == 0) {
                            queue.add(nextX);
                            queue.add(nextY);
                            distance[nextX][nextY] = distance[thisX][thisY] + 1;
                        }

                        visited[nextX][nextY] = 1;
                    }
                }
            }
        }
        int maxVal = Integer.MIN_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][j] == Integer.MIN_VALUE) {
                    return -1;
                }
                if (distance[i][j] > maxVal) {
                    maxVal = distance[i][j];
                }
            }
        }
        return maxVal;
    }

    @Test
    void test1() {
        int[][] grid = {{2,1,1},{1,1,0},{0,1,1}};
        int expected = 4;
        int actual = orangesRotting(grid);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[][] grid = {{2,1,1},{0,1,1},{1,0,1}};
        int expected = -1;
        int actual = orangesRotting(grid);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int[][] grid = {{0,2}};
        int expected = 0;
        int actual = orangesRotting(grid);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest() {
        int[][] grid = {{0,2,2}};
        int expected = 0;
        int actual = orangesRotting(grid);
        Assertions.assertEquals(expected, actual);
    }
}
