package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class SummaryRanges {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<>();
        int firstPointer = 0;
        while (firstPointer < nums.length){
            int secondPointer = firstPointer + 1;
            while (secondPointer < nums.length && nums[secondPointer] - nums[secondPointer - 1] == 1) {
                secondPointer++;
            }
            secondPointer --;
            if (nums[firstPointer] != nums[secondPointer]) {
                res.add(nums[firstPointer] + "->" + nums[secondPointer]);
            }
            else {
                res.add(nums[firstPointer] + "");
            }
            firstPointer = secondPointer + 1;
        }
        return res;
    }
}
