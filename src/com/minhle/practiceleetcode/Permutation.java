package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Permutation {
    public List<List<Integer>> permute(int[] nums) {
        List<Integer> numLinked = new LinkedList<>();
        for (int i : nums) {
            numLinked.add(i);
        }
        return permuteR(numLinked);
    }

    private List<List<Integer>> permuteR(List<Integer> nums) {
        List<List<Integer>> results = new LinkedList<>();
        if (nums.size() == 1) {
            List<Integer> r = new ArrayList<>();
            r.add(nums.get(0));
            results.add(r);
            return results;
        }
        for (int i = 0; i < nums.size(); i++) {
            int n = nums.remove(0);
            List<List<Integer>> resultsR = permuteR(nums);
            for (List<Integer> r : resultsR) {
                r.add(n);
                results.add(r);
            }
            nums.add(n);
        }
        return results;
    }
}
