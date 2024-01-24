package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class SortArrayByParityII {
    public int[] sortArrayByParityII(int[] nums) {
        List<Integer> oddValues = new ArrayList<>();
        List<Integer> evenValues = new ArrayList<>();

        for (int num : nums) {
            if (num % 2 != 0) {
                oddValues.add(num);
            } else {
                evenValues.add(num);
            }
        }
        boolean isOdd = false;
        int oddIndex = 0;
        int evenIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            if (isOdd) {
                nums[i] = oddValues.get(oddIndex++);
            }
            else {
                nums[i] = evenValues.get(evenIndex++);
            }
            isOdd = !isOdd;
        }
        return nums;
    }
}
