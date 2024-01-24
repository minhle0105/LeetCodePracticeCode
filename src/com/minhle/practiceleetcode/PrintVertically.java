package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class PrintVertically {
    public List<String> printVertically(String s) {
        String[] sSplit = s.split(" ");
        int longest = 0;
        for (String word : sSplit) {
            longest = Math.max(longest, word.length());
        }
        char[][] matrix = new char[sSplit.length][longest];
        for (int i = 0; i < matrix.length; i++) {
            StringBuilder word = new StringBuilder(sSplit[i]);
            while (word.length() < longest) {
                word.append(" ");
            }
            matrix[i] = word.toString().toCharArray();
        }
        List<String> res = new ArrayList<>();
        for (int c = 0; c < matrix[0].length; c++) {
            StringBuilder thisRes = new StringBuilder();
            for (int r = 0; r < matrix.length; r++) {
                thisRes.append(matrix[r][c]);
            }
            char[] process = thisRes.toString().toCharArray();
            int lastChar = -1;
            for (int i = process.length - 1; i >= 0; i--) {
                if (Character.isAlphabetic(process[i])) {
                    lastChar = i;
                    break;
                }
            }
            if (lastChar == -1) {
                res.add(thisRes.toString());
            }
            else {
                res.add(thisRes.substring(0, lastChar + 1));
            }
        }
        return res;
    }
}
