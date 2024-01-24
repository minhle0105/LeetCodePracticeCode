package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SubarraySumDivisibleByK {
    public int subarraysDivByK(int[] nums, int k) {
        int[] cumulativeSum = new int[nums.length + 1];
        for (int i = 1; i < cumulativeSum.length; i++) {
            cumulativeSum[i] = cumulativeSum[i - 1] + nums[i - 1];
        }
        int count = 0;
        for (int i = 0; i < cumulativeSum.length - 1; i++) {
            for (int j = i + 1; j < cumulativeSum.length; j++) {
                int sum = cumulativeSum[j] - cumulativeSum[i];
                if (sum % k == 0){
                    count++;
                }
            }
        }
        return count;
    }

    @Test
    void test1() {
        int[] nums = {4,5,0,-2,-3,1};
        int k = 5;
        Assertions.assertEquals(7, subarraysDivByK(nums, k));
    }
}
