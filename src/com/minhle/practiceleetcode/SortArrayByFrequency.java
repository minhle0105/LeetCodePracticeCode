package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class SortArrayByFrequency {

    private HashMap<Integer, Integer> countFrequency(int[] nums) {
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int i : nums) {
            if (count.containsKey(i)) {
                count.put(i, count.get(i) + 1);
            }
            else {
                count.put(i, 1);
            }
        }
        return count;
    }

    public int[] frequencySort(int[] nums) {
        List<Integer> numbers = new ArrayList<>();
        for (int i : nums) {
            numbers.add(i);
        }
        HashMap<Integer, Integer> frequencyCount = countFrequency(nums);
        numbers.sort((n1, n2) -> {
            int frequency1 = frequencyCount.get(n1);
            int frequency2 = frequencyCount.get(n2);
            if (frequency1 != frequency2) {
                return frequency1 - frequency2;
            }
            return n2 - n1;
        });
        int[] result = new int[nums.length];
        int count = 0;
        for (Integer i : numbers) {
            result[count++] = i;
        }
        return result;
    }

    @Test
    void firstTest() {
        int[] nums = new int[]{1,1,2,2,2,3};
        int[] expected = new int[]{3,1,1,2,2,2};
        int[] actual = frequencySort(nums);
        Assertions.assertArrayEquals(expected, actual);
    }
}
