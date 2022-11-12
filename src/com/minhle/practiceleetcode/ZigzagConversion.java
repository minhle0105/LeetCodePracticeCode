package com.minhle.practiceleetcode;
import java.util.*;

public class ZigzagConversion {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        char[][] zigzag = new char[numRows][1000];
        for (char[] row : zigzag) {
            Arrays.fill(row, ' ');
        }
        int ind = 0;
        int currentR = 0;
        int currentC = 0;
        int charFills = 0;
        while (charFills < s.length() && ind < s.length()) {
            while (currentR < numRows && charFills < s.length()) {
                zigzag[currentR][currentC] = s.charAt(ind);
                charFills++;
                ind++;
                currentR++;
            }
            currentR-=2;
            currentC++;
            while (currentR >= 0 && charFills < s.length()) {
                zigzag[currentR][currentC] = s.charAt(ind);
                charFills++;
                ind++;
                currentC++;
                currentR--;
            }
            currentR += 2;
            currentC--;
        }
        StringBuilder res = new StringBuilder();
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c <= currentC; c++) {
                char thisChar = zigzag[r][c];
                if (thisChar == '.' | thisChar == ',' | Character.isAlphabetic(thisChar)) {
                    res.append(thisChar);
                }
            }
        }
        return res.toString();
    }
}
