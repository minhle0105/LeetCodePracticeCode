package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Stack;

public class TheMazeII {
    static final int[][] maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    static final int[] dR = {-1, 1, 0, 0};
    static final int[] dC = {0, 0, -1, 1};

    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        int row = maze.length;
        int column = maze[0].length;
        int[][] visited = new int[row][column];
        int[][] levels = new int[row][column];
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
            for (int i = 0; i < 4; i ++) {
                int nextX = thisX;
                int nextY = thisY;
                boolean inBound = 0 <= nextX && nextX < row && 0 <= nextY && nextY < column;
                if (!inBound && visited[nextX][nextY] == 1) {
                    continue;
                }
                int count = levels[thisX][thisY];
                while (0 <= nextX + dR[i] && nextX + dR[i] < row && 0 <= nextY + dC[i] && nextY + dC[i] < column && maze[nextX + dR[i]][nextY + dC[i]] == 0) {
                    nextX += dR[i];
                    nextY += dC[i];
                    count++;
                }

                if (visited[nextX][nextY] == 0) {
                    visited[nextX][nextY] = 1;
                    stack.push(nextY);
                    stack.push(nextX);
                    levels[nextX][nextY] = count;
                }
            }
        }
        return levels[destination[0]][destination[1]] != 0 ? levels[destination[0]][destination[1]] : -1;
    }

    @Test
    void test1() {
        int[] start = {0,4};
        int[] dest = {3,2};
        int expected = -1;
        int actual = shortestDistance(maze, start, dest);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] start = {0,4};
        int[] dest = {4,4};
        int expected = 12;
        int actual = shortestDistance(maze, start, dest);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int[][] maze = {{0,0,0,0,0},{1,1,0,0,1},{0,0,0,0,0},{0,1,0,0,1},{0,1,0,0,0}};
        int[] start = {4,3};
        int[] dest = {0,1};
        int expected = -1;
        int actual = shortestDistance(maze, start, dest);
        Assertions.assertEquals(expected, actual);
    }


}
