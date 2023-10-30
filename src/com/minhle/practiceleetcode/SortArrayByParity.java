package com.minhle.practiceleetcode;

import java.util.*;

public class SortArrayByParity {
    public int[] sortArrayByParity(int[] nums) {
        List<Integer> numbers = new ArrayList<>();
        for (int i : nums) {
            numbers.add(i);
        }
        numbers.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(o1 % 2, o2 % 2);
            }
        });
        for (int i = 0; i < nums.length; i ++) {
            nums[i] = numbers.get(i);
        }
        return nums;
    }
}
