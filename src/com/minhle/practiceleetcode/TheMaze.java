package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Stack;

public class TheMaze {

    static final int[][] maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    static final int[] dR = {-1, 1, 0, 0};
    static final int[] dC = {0, 0, -1, 1};

    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        int row = maze.length;
        int column = maze[0].length;
        int[][] visited = new int[row][column];
        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze[i].length; j++) {
                if (maze[i][j] == 1) {
                    visited[i][j] = 1;
                }
            }
        }
        Stack<Integer> stack = new Stack<>();
        stack.push(start[1]);
        stack.push(start[0]);
        visited[start[0]][start[1]] = 1;
        while (!stack.isEmpty()) {
            int thisX = stack.pop();
            int thisY = stack.pop();
            if (thisX == destination[0] && thisY == destination[1]) {
                return true;
            }
            for (int i = 0; i < 4; i ++) {
                int nextX = thisX;
                int nextY = thisY;
                boolean inBound = 0 <= nextX && nextX < row && 0 <= nextY && nextY < column;
                if (!inBound && visited[nextX][nextY] == 1) {
                    continue;
                }
                while (0 <= nextX + dR[i] && nextX + dR[i] < row && 0 <= nextY + dC[i] && nextY + dC[i] < column && maze[nextX + dR[i]][nextY + dC[i]] == 0) {
                    nextX += dR[i];
                    nextY += dC[i];
                }

                if (visited[nextX][nextY] == 0) {
                    visited[nextX][nextY] = 1;
                    stack.push(nextY);
                    stack.push(nextX);
                }
            }
        }
        return false;
    }

    @Test
    void test1() {
        int[] start = {0,4};
        int[] dest = {4,4};
        Assertions.assertTrue(hasPath(maze, start, dest));
    }

    @Test
    void test2() {
        int[] start = {0,4};
        int[] dest = {3,2};
        Assertions.assertFalse(hasPath(maze, start, dest));
    }

    @Test
    void test3() {
        int[] start = {0,4};
        int[] dest = {4,1};
        Assertions.assertFalse(hasPath(maze, start, dest));
    }
}
