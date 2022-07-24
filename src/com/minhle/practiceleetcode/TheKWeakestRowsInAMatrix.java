package com.minhle.practiceleetcode;

import java.util.Arrays;

public class TheKWeakestRowsInAMatrix {
    static class Row implements Comparable<Row> {
        int nSoldiers;
        int nCivilians;
        int index;

        public Row(int[] data, int index) {
            for (int i : data) {
                if (i == 0) {
                    nCivilians++;
                }
                if (i == 1) {
                    nSoldiers++;
                }
            }
            this.index = index;
        }

        @Override
        public int compareTo(Row o) {
            if (this.nSoldiers == o.nSoldiers) {
                return Integer.compare(this.index, o.index);
            }
            return Integer.compare(this.nSoldiers, o.nSoldiers);
        }
    }
    public int[] kWeakestRows(int[][] mat, int k) {
        Row[] rows = new Row[mat.length];
        for (int i = 0; i < mat.length; i++) {
            rows[i] = new Row(mat[i], i);
        }
        Arrays.sort(rows);
        int[] res = new int[k];
        for (int i = 0; i < res.length; i++) {
            res[i] = rows[i].index;
        }
        return res;
    }
}
