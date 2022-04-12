package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class GameOfLife {

    final int[] dR = {0, 0, 1, -1, 1, 1, -1, -1};
    final int[] dC = {1, -1, 0, 0, 1, -1, 1, -1};

    private int countNeighbors(int[][] board, int i, int j, int nRows, int nCols) {
        int count = 0;
        for (int c = 0; c < 8; c++) {
            int nextI = i + dR[c];
            int nextJ = j + dC[c];
            boolean isInBound = nextI >= 0 && nextI < nRows && nextJ >= 0 && nextJ < nCols;
            if (isInBound) {
                if (board[nextI][nextJ] == 1) {
                    count ++;
                }
            }
        }
        return count;
    }

    public void gameOfLife(int[][] board) {
        int nRows = board.length;
        int nCols = board[0].length;
        int[][] initialState = new int[nRows][nCols];
        for (int i = 0; i < nRows; i++) {
            System.arraycopy(board[i], 0, initialState[i], 0, nCols);
        }
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                int liveNeighbors = countNeighbors(initialState, i, j, nRows, nCols);
                if (initialState[i][j] == 0) {
                    board[i][j] = liveNeighbors == 3 ? 1 : 0;
                }
                else {
                    if (liveNeighbors < 2) {
                        board[i][j] = 0;
                    }
                    else if (liveNeighbors == 2 || liveNeighbors == 3) {
                        board[i][j] = board[i][j];
                    }
                    else {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }

    @Test
    void test1() {
        int[][] board = {
                {0,1,0},
                {0,0,1},
                {1,1,1},
                {0,0,0}
        };
        int[][] expected = {
                {0,0,0},
                {1,0,1},
                {0,1,1},
                {0,1,0}
        };
        gameOfLife(board);
        Assertions.assertArrayEquals(expected, board);
    }
}
