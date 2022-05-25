package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class MissingRanges {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> ranges = new ArrayList<>();
        if (nums.length == 0) {
            String range = "";
            if (upper - lower >= 1) {
                range = lower + "->" + upper + "";
            }
            else {
                range = lower + "";
            }
            ranges.add(range);
            return ranges;
        }
        Set<Long> set = new HashSet<>();
        List<Long> allNumbers = new ArrayList<>();
        for (int num : nums) {
            set.add((long) num);
        }
        for (long i = lower; i <= upper; i++) {
            allNumbers.add(i);
        }
        int i = 0;
        while (i < allNumbers.size()) {
            if (!set.contains(allNumbers.get(i))) {
                int pointer = i + 1;
                while (pointer < allNumbers.size() && (!set.contains(allNumbers.get(pointer)))) {
                    pointer++;
                }
                String range = "";
                if (pointer == i + 1) {
                    range = allNumbers.get(i) + "";
                }
                else {
                    range = allNumbers.get(i) + "->" + allNumbers.get(pointer - 1) + "";
                }
                ranges.add(range);
                i = pointer;
            }
            else {
                i++;
            }
        }

        return ranges;
    }

    @Test
    void test1() {
        int[] nums = {0,1,3,50,75};
        int lower = 0;
        int upper = 99;
        List<String> expected = Arrays.asList("2","4->49","51->74","76->99");
        List<String> actual = findMissingRanges(nums, lower, upper);
        Assertions.assertEquals(expected, actual);
    }
    @Test
    void test2() {
        int[] nums = {-1};
        int lower = -1;
        int upper = -0;
        List<String> expected = Arrays.asList("0");
        List<String> actual = findMissingRanges(nums, lower, upper);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void tle() {
        int[] nums = {1000000000};
        int lower = 0;
        int upper = 1000000000;
        List<String> expected = Arrays.asList("0");
        List<String> actual = findMissingRanges(nums, lower, upper);
        Assertions.assertEquals(expected, actual);
    }

}
