package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class RemovingMinMaxFromArray {

    private int getMinIndex(int[] nums) {
        int minVal = nums[0];
        int minIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    private int getMaxIndex(int[] nums) {
        int maxVal = nums[0];
        int maxIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    public int minimumDeletions(int[] nums) {
        int minIndex = getMinIndex(nums);
        int maxIndex = getMaxIndex(nums);
        int deleteMinFromLeft = minIndex + 1;
        int deleteMinFromRight = nums.length - minIndex;
        int deleteMaxFromLeft = maxIndex + 1;
        int deleteMaxFromRight = nums.length - maxIndex;
        // trường hợp 1: nếu có thể 1 lần đi xoá luôn cả min cả max
        int bestDeleteFromLeft = Math.max(deleteMaxFromLeft, deleteMinFromLeft);
        int bestDeleteFromRight = Math.max(deleteMaxFromRight, deleteMinFromRight);
        int resultOfFirstCase = Math.min(bestDeleteFromLeft, bestDeleteFromRight);

        // trường hợp 2: xoá min và max từ 2 đầu
        int minDeleteMin = Math.min(deleteMinFromLeft, deleteMinFromRight);
        int minDeleteMax = Math.min(deleteMaxFromLeft, deleteMaxFromRight);
        int resultOfSecondCase = minDeleteMax + minDeleteMin;

        // trả về kết quả nào nhỏ hơn
        return Math.min(resultOfFirstCase, resultOfSecondCase);
    }

    @Test
    void firstTest(){
        int[] nums = {2,10,7,5,4,1,8,6};
        int expected = 5;
        int actual = minimumDeletions(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest(){
        int[] nums = {0,-4,19,1,8,-2,-3,5};
        int expected = 3;
        int actual = minimumDeletions(nums);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest(){
        int[] nums = {-1,-53,93,-42,37,94,97,82,46,42,-99,56,-76,-66,-67,-13,10,66,85,-28};
        int expected = 11;
        int actual = minimumDeletions(nums);
        Assertions.assertEquals(expected, actual);
    }
}
