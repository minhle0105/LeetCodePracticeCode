package com.minhle.practiceleetcode;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class NearestExitFromEntranceInMaze {
    final int[] dR = {1, -1, 0, 0};
    final int[] dC = {0, 0, 1, -1};
    final char EMPTY = '.';
    final char WALL = '+';
    public int nearestExit(char[][] maze, int[] entrance) {
        Set<int[]> exitPoints = new HashSet<>();
        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze[i].length; j++) {
                boolean isOnBound = i == 0 || i == maze.length - 1 || j == 0 || j == maze[i].length - 1;
                boolean isNotEntrance = !(i == entrance[0] && j == entrance[1]);
                boolean isEmptyCell = maze[i][j] == EMPTY;
                if (isOnBound && isNotEntrance && isEmptyCell) {
                    exitPoints.add(new int[]{i, j});
                }
            }
        }
        Queue<Integer> queue = new LinkedList<>();
        int[][] visited = new int[maze.length][maze[0].length];
        queue.add(entrance[0]);
        queue.add(entrance[1]);
        visited[entrance[0]][entrance[1]] = 1;
        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze[i].length; j++) {
                if (maze[i][j] == WALL) {
                    visited[i][j] = 1;
                }
            }
        }
        int[][] levels = new int[maze.length][maze[0].length];
        while (!queue.isEmpty()) {
            int thisRow = queue.remove();
            int thisCol = queue.remove();
            for (int i = 0; i < 4; i++) {
                int nextRow = thisRow + dR[i];
                int nextCol = thisCol + dC[i];
                boolean isInBound = nextRow >= 0 && nextRow < maze.length && nextCol >= 0 && nextCol < maze[0].length;
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
        for (int[] exit : exitPoints) {
            int r = exit[0];
            int c = exit[1];
            if (visited[r][c] == 0) {
                continue;
            }
            res = Math.min(res, levels[r][c]);
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }

    @Test
    void test1() {
        char[][] maze = {
                {'+','+','.','+'},
                {'.','.','.','+'},
                {'+','+','+','.'}
        };
        int[] entrance = {1,2};
        Assertions.assertEquals(1,nearestExit(maze, entrance));
    }
}
