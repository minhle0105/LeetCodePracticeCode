package com.minhle.practiceleetcode;

import java.util.*;

public class ShuffleAnArray {
    int[] originalArray;
    List<Integer> shuffleArray;

    public ShuffleAnArray(int[] nums) {
        this.originalArray = new int[nums.length];
        this.shuffleArray = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            originalArray[i] = nums[i];
            shuffleArray.add(nums[i]);
        }
    }

    public int[] reset() {
        return originalArray;
    }

    public int[] shuffle() {
        Collections.shuffle(shuffleArray);
        int[] res = new int[shuffleArray.size()];
        int i = 0;
        while (i < res.length) {
            res[i] = shuffleArray.get(i);
            i++;
        }
        return res;
    }
}
