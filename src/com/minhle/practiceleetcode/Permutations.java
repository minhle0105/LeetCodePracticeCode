package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Permutations {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> permutations = new ArrayList<>();
        generatePermutations(new ArrayList<>(), nums, permutations);
        return permutations;
    }

    private void generatePermutations(List<Integer> choices, int[] nums, List<List<Integer>> permutations) {
        if (choices.size() == nums.length) {
            permutations.add(new ArrayList<>(choices));
            return;
        }
        for (int num : nums) {
            if (choices.contains(num)) {
                continue;
            }
            choices.add(num);
            generatePermutations(choices, nums, permutations);
            choices.remove(choices.size() - 1);
        }
    }
}
