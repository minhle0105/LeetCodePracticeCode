package com.minhle.practiceleetcode;

public class SudokuSolver {

    static char[][] board;

    private static final char EMPTY = '.';
    private static int nRows;
    private static int nCols;

    private static char[] values;
    private static int subRegionSize;

    public void solveSudoku(char[][] board) {
        SudokuSolver.board = board;
        nRows = board.length;
        nCols = board[0].length;
        subRegionSize = (int) Math.sqrt(nRows);
        values = new char[nRows];
        for (int i = 0; i < values.length; i++) {
            values[i] = (char) (i + '1');
        }
        solveSudoku(0, 0);
    }

    private boolean solveSudoku(int row, int col) {
        if (col == nCols) {
            col = 0;
            row++;
            if (row == nRows) {
                return true;
            }
        }

        if (board[row][col] != EMPTY) {
            return solveSudoku(row, col + 1);
        }
        for (int i = 0; i < values.length; i++) {
            if (canPlaceValue(row, col, values[i])) {
                placeValue(row, col, i);
                if (solveSudoku(row, col + 1)) {
                    return true;
                }
                else {
                    rollback(row, col);
                }
            }
        }
        return false;

    }

    private void placeValue(int row, int col, int i) {
        SudokuSolver.board[row][col] = values[i];
    }

    private void rollback(int row, int col) {
        SudokuSolver.board[row][col] = EMPTY;
    }


    private boolean canPlaceValue(int row, int col, char value) {
        // check dong
        for (char[] boardRow : board) {
            if (boardRow[col] == value) {
                return false;
            }
        }

        // check cot
        for (int i = 0; i < nCols; i++) {
            if (board[row][i] == value) {
                return false;
            }
        }
        int[] startCoordinates = calculateTopSubregionIndexes(row, col);
        int startRow = startCoordinates[0];
        int startCol = startCoordinates[1];
        for (int r = startRow; r < (startRow + subRegionSize); r++) {
            for (int c = startCol; c < (startCol + subRegionSize); c++) {
                if (r != row & c != col & board[r][c] == value) {
                    return false;
                }
            }
        }
        return true;

    }

    private int[] calculateTopSubregionIndexes(int row, int col) {
        int subRegionRow = row / subRegionSize;
        int subRegionCol = col / subRegionSize;
        int subRegionStartRow = subRegionRow * subRegionSize;
        int subRegionStartCol = subRegionCol * subRegionSize;
        return new int[]{subRegionStartRow, subRegionStartCol};
    }

}
