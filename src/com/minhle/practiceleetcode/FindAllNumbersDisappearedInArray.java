package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class FindAllNumbersDisappearedInArray {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        Set<Integer> hashSet = new HashSet<>();
        for (int i : nums) {
            hashSet.add(i);
        }
        List<Integer> result = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (!hashSet.contains(i)) {
                result.add(i);
            }
        }
        return result;
    }

    @Test
    void firstTest () {
        int[] nums = {4,3,2,7,8,2,3,1};
        List<Integer> actual = findDisappearedNumbers(nums);
        List<Integer> expected = Arrays.asList(5, 6);
        int[] actualArr = new int[actual.size()];
        int[] expectedArr = new int[expected.size()];
        for (int i = 0; i < actual.size(); i++) {
            actualArr[i] = actual.get(i);
            expectedArr[i] = expected.get(i);
        }
        Assertions.assertArrayEquals(expectedArr, actualArr);
    }

    @Test
    void secondTest() {
        int[] nums = {1,1};
        List<Integer> actual = findDisappearedNumbers(nums);
        List<Integer> expected = Collections.singletonList(2);
        int[] actualArr = new int[actual.size()];
        int[] expectedArr = new int[expected.size()];
        for (int i = 0; i < actual.size(); i++) {
            actualArr[i] = actual.get(i);
            expectedArr[i] = expected.get(i);
        }
        Assertions.assertArrayEquals(expectedArr, actualArr);
    }


}
