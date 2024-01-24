package com.minhle.practiceleetcode;

public class DeleteColumnsToMakeSorted {
    public int minDeletionSize(String[] strs) {
        int res = 0;
        int nRows = strs.length;
        int nCols = strs[0].length();
        for (int c = 0; c < nCols; c++) {
            for (int r = 0; r < nRows - 1; r++) {
                char c1 = strs[r].charAt(c);
                char c2 = strs[r + 1].charAt(c);
                if (c1 > c2) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
}
