package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SubarraySumEqualsK {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        int[] cumulativeSum = new int[nums.length + 1];
        for (int i = 1; i < cumulativeSum.length; i++) {
            cumulativeSum[i] = cumulativeSum[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < cumulativeSum.length - 1; i++) {
            for (int j = i + 1; j < cumulativeSum.length; j++) {
                int sum = cumulativeSum[j] - cumulativeSum[i];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }


    @Test
    void test1() {
        int[] nums = {1,1,1};
        int k = 2;
        Assertions.assertEquals(2, subarraySum(nums, k));
    }

    @Test
    void test2() {
        int[] nums = {1,2,3};
        int k = 3;
        Assertions.assertEquals(2, subarraySum(nums, k));
    }

    @Test
    void test3() {
        int[] nums = {1,2,1,2,1};
        int k = 3;
        Assertions.assertEquals(4, subarraySum(nums, k));
    }

    @Test
    void test4() {
        int[] nums = {1};
        int k = 0;
        Assertions.assertEquals(0, subarraySum(nums, k));
    }

    @Test
    void test5() {
        int[] nums = {1, -1, 0};
        int k = 0;
        Assertions.assertEquals(3, subarraySum(nums, k));
    }

    @Test
    void test6() {
        int[] nums = {3,4,7,2,-3,1,4,2};
        int k = 7;
        Assertions.assertEquals(4, subarraySum(nums, k));
    }
}
