package com.minhle.practiceleetcode;

import java.util.Scanner;
import java.util.Stack;

public class TheMaze {

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
                int nextX = thisX + dR[i];
                int nextY = thisY + dC[i];
                boolean inBound = 0 <= nextX && nextX < row && 0 <= nextY && nextY < column;
                if (!inBound) {
                    continue;
                }
                while (0 <= nextX + dR[i] && nextX + dR[i] < row && 0 <= nextY + dC[i] && nextY + dC[i] < column && maze[nextX][nextY] == 0) {
                    nextX += dR[i];
                    nextY += dC[i];
                    visited[nextX][nextY] = 1;
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

    public static void main(String[] args) {
        int[][] maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
        int[] start = {0,4};
        int[] dest = {4,4};

        int[][] maze2 = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
        int[] start2 = {0,4};
        int[] dest2 = {3,2};

        int[][] maze3 = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
        int[] start3 = {0,4};
        int[] dest3 = {1,2};

        TheMaze theMaze = new TheMaze();
        System.out.println(theMaze.hasPath(maze, start, dest));
//        System.out.println(theMaze.hasPath(maze2, start2, dest2));
//        System.out.println(theMaze.hasPath(maze3, start3, dest3));
    }
}
