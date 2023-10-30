package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class FindKClosetElements {
    static class Diff implements Comparable<Diff> {
        int index;
        int difference;
        public Diff (int index, int difference) {
            this.index = index;
            this.difference = difference;
        }
        @Override
        public int compareTo(Diff o) {
            return Integer.compare(this.difference, o.difference);
        }
    }
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        Diff[] diffs = new Diff[arr.length];
        for (int i = 0; i < arr.length; i++) {
            diffs[i] = new Diff(i, Math.abs(arr[i] - x));
        }
        Arrays.sort(diffs);
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            res.add(arr[diffs[i].index]);
        }
        Collections.sort(res);
        return res;
    }
}
