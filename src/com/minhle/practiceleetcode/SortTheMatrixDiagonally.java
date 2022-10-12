package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SortTheMatrixDiagonally {
    public int[][] diagonalSort(int[][] mat) {
        int r = 0;
        int c = 0;
        while (r < mat.length && c < mat[0].length) {
            List<Integer> thisDiag = new ArrayList<>();
            int currR = r;
            int currC = c;
            while (currR < mat.length && currC < mat[0].length) {
                thisDiag.add(mat[currR][currC]);
                currR++;
                currC++;
            }
            Collections.sort(thisDiag);
            int ind = 0;
            currR = r;
            currC = c;
            while (currR < mat.length && currC < mat[0].length) {
                mat[currR][currC] = thisDiag.get(ind);
                ind++;
                currR++;
                currC++;
            }
            r++;
        }
        r = 0;
        c = 0;
        while (r < mat.length && c < mat[0].length) {
            List<Integer> thisDiag = new ArrayList<>();
            int currR = r;
            int currC = c;
            while (currR < mat.length && currC < mat[0].length) {
                thisDiag.add(mat[currR][currC]);
                currR++;
                currC++;
            }
            Collections.sort(thisDiag);
            int ind = 0;
            currR = r;
            currC = c;
            while (currR < mat.length && currC < mat[0].length) {
                mat[currR][currC] = thisDiag.get(ind);
                ind++;
                currR++;
                currC++;
            }
            c++;
        }
        return mat;
    }
}
