package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SignOfProductOfArray {
    public int arraySign(int[] nums) {
        int countNeg = 0;
        for (int num : nums) {
            if (num == 0) {
                return 0;
            }
            if (num < 0) {
                countNeg ++;
            }
        }
        return countNeg % 2 == 0 ? 1 : -1;
    }

    @Test
    void test1() {
        int[] nums = {-1,-2,-3,-4,3,2,1};
        int expected = 1;
        int actual = arraySign(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] nums = {1,5,0,2,-3};
        int expected = 0;
        int actual = arraySign(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int[] nums = {-1,1,-1,1,-1};
        int expected = -1;
        int actual = arraySign(nums);
        Assertions.assertEquals(expected, actual);
    }
}
