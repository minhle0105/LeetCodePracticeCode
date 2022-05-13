package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class FindTriangleSumOfArray {
    public int triangularSum(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int[] sum = getNextSumRows(nums);
        return (sum[0] + sum[1]) % 10;
    }

    private int[] getNextSumRows(int[] prevRow) {
        if (prevRow.length == 2) {
            return prevRow;
        }
        int[] thisRow = new int[prevRow.length - 1];
        for (int i = 0; i < thisRow.length; i++) {
            thisRow[i] = (prevRow[i] + prevRow[i + 1]) % 10;
        }
        return getNextSumRows(thisRow);
    }

    @Test
    void test1() {
        int[] nums = {1, 2, 3, 4, 5};
        int expected = 8;
        int actual = triangularSum(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] nums = {2,6,6,5,5,3,3,8,6,4,3,3,5,1,0,1,3,6,9};
        int expected = 0;
        int actual = triangularSum(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int[] nums = {2};
        int expected = 2;
        int actual = triangularSum(nums);
        Assertions.assertEquals(expected, actual);
    }
}
