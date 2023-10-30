package com.minhle.practiceleetcode;

import java.util.*;
public class DiagonalTraverse {
    public int[] findDiagonalOrder(int[][] mat) {
        List<List<Integer>> res = new ArrayList<>();
        traverseVertically(mat, 0, res);
        traverseHorizontally(mat, mat.length - 1, 1, res);
        int m = mat.length;
        int n = mat[0].length;
        int[] answers = new int[m * n];
        int i = 0;
        boolean isReversed = false;
        for (List<Integer> nums : res) {
            if (isReversed) {
                for (int j = nums.size() - 1; j >= 0; j--) {
                    answers[i++] = nums.get(j);
                }
            }
            else {
                for (Integer num : nums) {
                    answers[i++] = num;
                }
            }
            isReversed = !isReversed;
        }
        return answers;
    }
    private void traverseVertically(int[][] mat, int r, List<List<Integer>> res) {
        if (r == mat.length) {
            return;
        }
        int currR = r;
        int currC = 0;
        List<Integer> thisDiag = new ArrayList<>();
        while (currR >= 0 && currC < mat[0].length) {
            thisDiag.add(mat[currR][currC]);
            currR--;
            currC++;
        }
        res.add(thisDiag);
        traverseVertically(mat, r + 1, res);
    }
    private void traverseHorizontally(int[][] mat, int r, int c, List<List<Integer>> res) {
        if (c == mat[0].length) {
            return;
        }
        int currR = r;
        int currC = c;
        List<Integer> thisDiag = new ArrayList<>();
        while (currR >= 0 && currC < mat[0].length) {
            thisDiag.add(mat[currR][currC]);
            currR--;
            currC++;
        }
        res.add(thisDiag);
        traverseHorizontally(mat, r, c + 1, res);
    }
}
