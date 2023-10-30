package com.minhle.practiceleetcode;

import java.util.*;

public class SetMismatch {
    public int[] findErrorNums(int[] nums) {
        Set<Integer> numsCount = new HashSet<>();
        int duplicateNumber = -1;
        for (int i : nums) {
            if (numsCount.contains(i)) {
                duplicateNumber = i;
            }
            else {
                numsCount.add(i);
            }
        }
        int n = nums.length;
        int missingNumber = -1;
        for (int i = 1; i <= n; i++) {
            if (!numsCount.contains(i)) {
                missingNumber = i;
                break;
            }
        }
        return new int[]{duplicateNumber, missingNumber};
    }
}
