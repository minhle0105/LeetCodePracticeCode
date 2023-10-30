package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.Queue;

public class IslandPerimeter {

    static final int[] dR = {-1, 1, 0, 0};
    static final int[] dC = {0, 0, -1, 1};

    public int islandPerimeter(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] visited = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    visited[i][j] = 1;
                }
            }
        }
        int[] startPoint = new int[2];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    startPoint[0] = i;
                    startPoint[1] = j;
                    break;
                }
            }
        }
        return bfs(grid, visited, startPoint, m, n);

    }

    private int bfs(int[][] graph, int[][] visited, int[] startPoint, int m, int n) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startPoint[0]);
        queue.add(startPoint[1]);
        visited[startPoint[0]][startPoint[1]] = 1;
        int perimeter = 0;
        while (!queue.isEmpty()) {
            int thisX = queue.remove();
            int thisY = queue.remove();
            int remaining = 4;
            for (int i = 0; i < 4; i++) {
                int nextX = thisX + dR[i];
                int nextY = thisY + dC[i];
                boolean isInBound = nextX >= 0 && nextX < m && nextY >= 0 && nextY < n;
                if (isInBound) {
                    if (graph[nextX][nextY] == 1) {
                        remaining--;
                    }
                    if (visited[nextX][nextY] == 0) {
                        queue.add(nextX);
                        queue.add(nextY);
                        visited[nextX][nextY] = 1;
                    }
                }
            }
            perimeter += remaining;
        }
        return perimeter;
    }

    @Test
    void test1() {
        int[][] grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
        int expected = 16;
        int actual = islandPerimeter(grid);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[][] grid = {{1}};
        int expected = 4;
        int actual = islandPerimeter(grid);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int[][] grid = {{1,0}};
        int expected = 4;
        int actual = islandPerimeter(grid);
        Assertions.assertEquals(expected, actual);
    }
}
