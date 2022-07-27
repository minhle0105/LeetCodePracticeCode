package com.minhle.practiceleetcode;

import java.util.HashSet;
import java.util.Set;

public class FirstMissingPositive {
    public int firstMissingPositive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        for (int i = 1; i <= nums.length; i++) {
            if (!set.contains(i)) {
                return i;
            }
        }
        return nums.length + 1;
    }
}
