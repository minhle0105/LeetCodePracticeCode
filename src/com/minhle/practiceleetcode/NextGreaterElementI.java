package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class NextGreaterElementI {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        List<Integer> results = new ArrayList<>();
        for (int value : nums1) {
            for (int j = 0; j < nums2.length; j++) {
                if (value == nums2[j]) {
                    boolean foundOne = false;
                    for (int k = j; k < nums2.length; k++) {
                        if (nums2[k] > nums2[j]) {
                            results.add(nums2[k]);
                            foundOne = true;
                            break;
                        }
                    }
                    if (!foundOne) {
                        results.add(-1);
                    }
                }
            }
        }
        int[] finResults = new int[results.size()];
        for (int i = 0; i < finResults.length; i++) {
            finResults[i] = results.get(i);
        }
        return finResults;
    }
}
