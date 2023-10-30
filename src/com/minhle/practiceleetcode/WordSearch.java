package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class WordSearch {

    static final int[] dR = {-1, 1, 0, 0};
    static final int[] dC = {0, 0, -1, 1};

    public boolean exist(char[][] board, String word) {
        int row = board.length;
        int column = board[0].length;

        List<int[]> possibleStartPoints = new ArrayList<>();
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < column; j++) {
                if (board[i][j] == word.charAt(0)) {
                    int[] point = new int[]{i,j};
                    possibleStartPoints.add(point);
                }
            }
        }

        for (int[] point : possibleStartPoints) {
            int[][] visited = new int[row][column];
            visited[point[0]][point[1]] = 1;
            if (dfs(board, visited, point, 1, word)) {
                return true;
            }
        }
        return false;
    }

    private static boolean dfs(char[][] map, int[][] visited, int[] startPoint, int pointer, String target) {
        if (pointer == target.length()) {
            return true;
        }

        boolean r = false;
        visited[startPoint[0]][startPoint[1]] = 1;
        for (int i = 0; i < 4; i++) {
            int nextX = startPoint[0] + dR[i];
            int nextY = startPoint[1] + dC[i];
            boolean inBound = nextX >= 0 && nextX < map.length && nextY >= 0 && nextY < map[0].length;
            if (inBound) {
                if (visited[nextX][nextY] == 0 && map[nextX][nextY] == target.charAt(pointer)) {
                    int[] nextStartPoint = new int[]{nextX, nextY};
                    r = r || dfs(map, visited, nextStartPoint, pointer + 1, target);
                }
            }
        }

        visited[startPoint[0]][startPoint[1]] = 0;
        return r;
    }

    @Test
    void firstTest() {
        char[][] map = {{'A','B','C','E'},
                        {'S','F','C','S'},
                        {'A','D','E','E'}};
        String target = "ABCCED";
        Assertions.assertTrue(exist(map, target));
    }

    @Test
    void secondTest() {
        char[][] map = {{'A','B','C','E'},
                        {'S','F','C','S'},
                        {'A','D','E','E'}};
        String target = "SEE";
        Assertions.assertTrue(exist(map, target));
    }

    @Test
    void lastTest() {
        char[][] map = {{'A','B','C','E'},
                        {'S','F','C','S'},
                        {'A','D','E','E'}};
        String target = "ABCB";
        Assertions.assertFalse(exist(map, target));
    }
}
