package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class PartitionArrayAccordingToGivenPivot {
    public int[] pivotArray(int[] nums, int pivot) {
        List<Integer> firstHalf = new ArrayList<>();
        List<Integer> secondHalf = new ArrayList<>();
        int countPivot = 0;
        for (int num : nums) {
            if (num < pivot) {
                firstHalf.add(num);
            }
            else if (num > pivot) {
                secondHalf.add(num);
            }
            else {
                countPivot++;
            }
        }
        int[] res = new int[nums.length];
        int index = 0;
        for (Integer value : firstHalf) {
            res[index++] = value;
        }
        for (int i = 0; i < countPivot; i++) {
            res[index++] = pivot;
        }

        for (Integer integer : secondHalf) {
            res[index++] = integer;
        }
        return res;
    }
}
