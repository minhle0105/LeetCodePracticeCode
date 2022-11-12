package com.minhle.interviews.RecRoom;
import java.util.*;

public class MatrixTraversal {
    static final int[] dR = {1, 1, 1};
    static final int[] dC = {-1, 0, 1};
    public static int maxEnergy(int[][] matrix) {
        // Write your code here
//        int[][] matrix = new int[mat.size()][mat.get(0).size()];
//        int ind = 0;
//        for (List<Integer> row : mat) {
//            int[] thisRow = new int[row.size()];
//            for (int i = 0; i < thisRow.length; i++) {
//                thisRow[i] = row.get(i);
//            }
//            matrix[ind++] = thisRow;
//        }
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < matrix[0].length; i++) {
            res.add(traverse(matrix, 0, i, 100));
        }
        return Collections.max(res);
    }

    private static int traverse(int[][] matrix, int r, int c, int energyLeft) {
        if (r == matrix.length ) {
            return energyLeft;
        }
        if (c > 0 && c < matrix[0].length) {
            int firstCase = traverse(matrix, r + 1, c - 1, energyLeft - matrix[r][c]);
            int secondCase = traverse(matrix, r + 1, c, energyLeft - matrix[r][c]);
            int thirdCase = traverse(matrix, r + 1, c + 1, energyLeft - matrix[r][c]);
            return Math.max(firstCase, Math.max(secondCase, thirdCase));
        }
        return Integer.MIN_VALUE;
    }

    public static void main(String[] args) {
        int[][] matrix = {
                {51, 52, 69, 45},
                {55,87,81,15},
                {63,28,66,63},
                {49,19,11,69}

        };
        System.out.println(maxEnergy(matrix));
    }
}
