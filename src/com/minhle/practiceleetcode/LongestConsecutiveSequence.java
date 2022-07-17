package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;


public class LongestConsecutiveSequence {
    public int longestConsecutive(int[] nums) {
        return longestConsecutiveUsingSet(nums);
        /*return longestConsecutiveUsingSort(nums);*/
    }

    public int longestConsecutiveUsingSet(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        int maxLength = 0;
        for (Integer num : set) {
            if (!set.contains(num - 1)) {
                int currentNum = num;
                int length = 1;
                while (set.contains(currentNum + 1)) {
                    currentNum++;
                    length++;
                }
                maxLength = Math.max(length, maxLength);
            }
        }
        return maxLength;
    }

    public int longestConsecutiveUsingSort(int[] nums) {
        if (nums.length <= 1) {
            return nums.length;
        }
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        nums = new int[set.size()];
        int i = 0;
        for (Integer key : set) {
            nums[i++] = key;
        }
        Arrays.sort(nums);
        int longest = 1;
        int firstPointer = 0;
        while (firstPointer < nums.length - 1) {
            int secondPointer = firstPointer + 1;
            int length = 1;
            while (secondPointer < nums.length && nums[secondPointer] - nums[secondPointer - 1] == 1) {
                length++;
                secondPointer++;
            }
            longest = Math.max(longest, length);
            firstPointer = secondPointer;
        }
        return longest;
    }

    @Test
    void test1() {
        int[] nums = {100, 4, 200, 1, 3, 2};
        int expected = 4;
        int actual = longestConsecutive(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] nums = {0,3,7,2,5,8,4,6,0,1};
        Assertions.assertEquals(9, longestConsecutive(nums));
    }

    @Test
    void test3() {
        int[] nums = {1,2,0,1};
        Assertions.assertEquals(3, longestConsecutive(nums));
    }
}
