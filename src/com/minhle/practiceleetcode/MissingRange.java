package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class MissingRange {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> results = new ArrayList<>();
        String arrow = "->";
        if (nums.length == 0) {
            if (upper - lower == 0) {
                results.add(lower + "");
            }
            else if (upper - lower == 1) {
                results.add((lower) + arrow + (upper));
            }
            else {
                results.add((lower) + arrow + (upper));
            }
            return results;
        }

        if (lower < nums[0]) {
            if (nums[0] - lower == 1) {
                results.add(lower + "");
            }
            else {
                results.add((lower) + arrow + (nums[0] - 1));
            }
        }
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i + 1] - nums[i] == 2) {
                results.add((nums[i] + 1) + "");
            }
            else if (nums[i + 1] - nums[i] > 2) {
                results.add((nums[i] + 1) + arrow + (nums[i + 1] - 1));
            }
        }
        if (upper > nums[nums.length - 1]) {
            if (upper - nums[nums.length - 1] == 1) {
                results.add(upper + "");
            }
            else {
                results.add((nums[nums.length - 1] + 1) + arrow + (upper));
            }
        }
        return results;
    }
}
