package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class ValidSudoku {
    final static String block = ".";

    private boolean checkRow(int row, String[][] board) {
        HashMap<String, Integer> hashMap = new HashMap<>();
        for (String c : board[row]) {
            if (c.equals(block)) {
                continue;
            }
            if (hashMap.containsKey(c)) {
                return false;
            } else {
                hashMap.put(c, 1);
            }
        }
        return true;
    }

    private boolean checkDuplicateInSubBoard(String[][] board) {
        HashMap<String, Integer> hashMap = new HashMap<>();
        for (String[] row : board) {
            for (String s : row) {
                if (s.equals(block)) {
                    continue;
                }
                if (hashMap.containsKey(s)) {
                    return false;
                } else {
                    hashMap.put(s, 1);
                }
            }
        }
        return true;
    }

    private boolean checkColumn(int column, String[][] board) {
        HashMap<String, Integer> hashMap = new HashMap<>();
        for (String[] row : board) {
            if (row[column].equals(block)) {
                continue;
            }
            if (hashMap.containsKey(row[column])) {
                return false;
            } else {
                hashMap.put(row[column], 1);
            }
        }
        return true;
    }

    private String[][] getSubBoard(String[][] board, int startSubBoardRow, int startSubBoardColumn) {
        String[][] subBoard = new String[3][3];
        int rowLimit = startSubBoardRow + 3;
        int columnLimit = startSubBoardColumn + 3;
        int initialColumn = startSubBoardColumn;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                subBoard[i][j] = board[startSubBoardRow][startSubBoardColumn++];
                if (startSubBoardColumn == columnLimit) {
                    startSubBoardRow += 1;
                    startSubBoardColumn = initialColumn;
                }
            }
        }
        return subBoard;

    }

    public boolean isValidSudoku(String[][] board) {
        for (int i = 0; i < board.length; i++) {
            if (!checkRow(i, board)) {
                return false;
            }
            if (!checkColumn(i, board)) {
                return false;
            }
        }
        int currentColumn = 0;
        for (int i = 0; i < board.length; ) {
            String[][] subBoard = getSubBoard(board, i, currentColumn);
            if (!checkDuplicateInSubBoard(subBoard)) {
                return false;
            }
            for (int j = 0; j < subBoard.length; j++) {
                if (!checkRow(j, subBoard)) {
                    return false;
                }
                if (!checkColumn(j, subBoard)) {
                    return false;
                }
            }
            currentColumn += 3;
            if (currentColumn == board.length) {
                i += 3;
                currentColumn = 0;
            }
        }
        return true;
    }

    @Test
    void firstTest() {
        String[][] board = {{"5", "3", ".", ".", "7", ".", ".", ".", "."}
                , {"6", ".", ".", "1", "9", "5", ".", ".", "."}
                , {".", "9", "8", ".", ".", ".", ".", "6", "."}
                , {"8", ".", ".", ".", "6", ".", ".", ".", "3"}
                , {"4", ".", ".", "8", ".", "3", ".", ".", "1"}
                , {"7", ".", ".", ".", "2", ".", ".", ".", "6"}
                , {".", "6", ".", ".", ".", ".", "2", "8", "."}
                , {".", ".", ".", "4", "1", "9", ".", ".", "5"}
                , {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
        Assertions.assertTrue(isValidSudoku(board));
    }

    @Test
    void secondTest() {
        String[][] board = {{"8", "3", ".", ".", "7", ".", ".", ".", "."}
                , {"6", ".", ".", "1", "9", "5", ".", ".", "."}
                , {".", "9", "8", ".", ".", ".", ".", "6", "."}
                , {"8", ".", ".", ".", "6", ".", ".", ".", "3"}
                , {"4", ".", ".", "8", ".", "3", ".", ".", "1"}
                , {"7", ".", ".", ".", "2", ".", ".", ".", "6"}
                , {".", "6", ".", ".", ".", ".", "2", "8", "."}
                , {".", ".", ".", "4", "1", "9", ".", ".", "5"}
                , {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
        Assertions.assertFalse(isValidSudoku(board));
    }

    @Test
    void failTest() {
        String[][] board = {{".", ".", ".", ".", "5", ".", ".", "1", "."},
                {".", "4", ".", "3", ".", ".", ".", ".", "."},
                {".", ".", ".", ".", ".", "3", ".", ".", "1"},
                {"8", ".", ".", ".", ".", ".", ".", "2", "."},
                {".", ".", "2", ".", "7", ".", ".", ".", "."},
                {".", "1", "5", ".", ".", ".", ".", ".", "."},
                {".", ".", ".", ".", ".", "2", ".", ".", "."},
                {".", "2", ".", "9", ".", ".", ".", ".", "."},
                {".", ".", "4", ".", ".", ".", ".", ".", "."}};
        Assertions.assertFalse(isValidSudoku(board));
    }

    @Test
    void failTest2() {
        String[][] board = {{".", ".", ".", ".", ".", ".", "5", ".", "."},
                {".", ".", ".", ".", ".", ".", ".", ".", "."},
                {".", ".", ".", ".", ".", ".", ".", ".", "."},
                {"9", "3", ".", ".", "2", ".", "4", ".", "."},
                {".", ".", "7", ".", ".", ".", "3", ".", "."},
                {".", ".", ".", ".", ".", ".", ".", ".", "."},
                {".", ".", ".", "3", "4", ".", ".", ".", "."},
                {".", ".", ".", ".", ".", "3", ".", ".", "."},
                {".", ".", ".", ".", ".", "5", "2", ".", "."}};
        Assertions.assertFalse(isValidSudoku(board));
    }
}
