package com.minhle.practiceleetcode;
import java.util.*;

public class FindTheTownJudge {
    Map<Integer, Set<Integer>> map = new HashMap<>();
    public int findJudge(int n, int[][] trust) {
        for (int i = 1; i <= n; i++) {
            map.put(i, new HashSet<>());
        }
        for (int[] t : trust) {
            map.get(t[0]).add(t[1]);
        }
        for (Integer key : map.keySet()) {
            if (map.get(key).size() == 0) {
                if (check(key)) {
                    return key;
                }
            }
        }
        return -1;
    }

    private boolean check(int ind) {
        for (Integer key : map.keySet()) {
            if (key == ind) {
                continue;
            }
            if (!map.get(key).contains(ind)) {
                return false;
            }
        }
        return true;
    }
}
