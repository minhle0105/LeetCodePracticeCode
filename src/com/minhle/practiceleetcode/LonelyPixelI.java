package com.minhle.practiceleetcode;

public class LonelyPixelI {
    public int findLonelyPixel(char[][] picture) {
        int count = 0;
        int m = picture.length;
        int n = picture[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B') {
                    boolean rowIsClear = checkRow(picture, i);
                    boolean columnIsClear = checkColumn(picture, j);
                    if (rowIsClear && columnIsClear) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    private boolean checkRow(char[][] picture, int row) {
        int count = 0;
        for (int i = 0; i < picture[row].length; i++) {
            if (picture[row][i] == 'B') {
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
        return true;
    }

    private boolean checkColumn(char[][] picture, int column) {
        int count = 0;
        for (char[] row : picture) {
            if (row[column] == 'B') {
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
}
