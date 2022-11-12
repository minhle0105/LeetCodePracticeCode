package com.minhle.practiceleetcode;
import java.util.*;

public class ZigzagConversion {
    public static String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        char[][] zigzag = new char[numRows][1000];
        for (char[] row : zigzag) {
            Arrays.fill(row, ' ');
        }
        int index = 0;
        int currentR = 0;
        int currentC = 0;
        while (index < s.length()) {
            while (currentR < numRows && index < s.length()) {
                zigzag[currentR][currentC] = s.charAt(index);
                index++;

                currentR++;
            }
            currentR-=2;
            currentC++;
            while (currentR >= 0 && index < s.length()) {
                zigzag[currentR][currentC] = s.charAt(index);
                index++;

                currentC++;
                currentR--;
            }
            currentR+=2;
            currentC--;
        }
        StringBuilder res = new StringBuilder();
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c <= currentC; c++) {
                char thisChar = zigzag[r][c];
                if (thisChar != ' ') {
                    res.append(thisChar);
                }
            }
        }
        return res.toString();
    }
}
