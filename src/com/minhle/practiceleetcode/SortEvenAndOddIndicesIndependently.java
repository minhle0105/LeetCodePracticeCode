package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SortEvenAndOddIndicesIndependently {
    public int[] sortEvenOdd(int[] nums) {
        List<Integer> oddIndices = new ArrayList<>();
        List<Integer> oddValues = new ArrayList<>();
        List<Integer> evenIndices = new ArrayList<>();
        List<Integer> evenValues = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (i % 2 != 0) {
                oddIndices.add(i);
                oddValues.add(nums[i]);
            }
            else {
                evenIndices.add(i);
                evenValues.add(nums[i]);
            }
        }

        Collections.sort(oddValues);
        Collections.reverse(oddValues);
        Collections.sort(evenValues);

        for (int i = 0; i < oddIndices.size(); i++) {
            nums[oddIndices.get(i)] = oddValues.get(i);
        }
        for (int i = 0; i < evenIndices.size(); i++) {
            nums[evenIndices.get(i)] = evenValues.get(i);
        }
        return nums;
    }
}
