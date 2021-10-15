package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SquaresOfSortedArray {

    private int getSquare(int num) {
        return num * num;
    }

    public int[] sortedSquares(int[] nums) {
        int splitPointer = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= 0) {
                splitPointer = i;
                break;
            }
        }
        int[] result = new int[nums.length];
        int counter = 0;
        if (splitPointer != -1) {
            int positivePointer = splitPointer;
            int negativePointer = splitPointer - 1;
            while (positivePointer < nums.length && negativePointer >= 0) {
                if (Math.abs(nums[negativePointer]) > Math.abs(nums[positivePointer])) {
                    result[counter++] = getSquare(nums[positivePointer++]);
                }
                else {
                    result[counter++] = getSquare(nums[negativePointer--]);
                }
            }
            if (positivePointer < nums.length) {
                while (positivePointer < nums.length) {
                    result[counter++] = getSquare(nums[positivePointer++]);
                }
            }
            if (negativePointer >= 0) {
                while (negativePointer >= 0) {
                    result[counter++] = getSquare(nums[negativePointer--]);
                }
            }
        }
        else {
            int lastPointer = nums.length - 1;
            while (lastPointer >= 0) {
                result[counter++] = getSquare(nums[lastPointer--]);
            }
        }
        return result;
    }

    @Test
    void firstTest() {
        int[] nums = {-5,-3,-2,-1};
        int[] expected = {1,4,9,25};
        int[] actual = sortedSquares(nums);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[] nums = {-4,-1,0,3,10};
        int[] expected = {0,1,9,16,100};
        int[] actual = sortedSquares(nums);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void thirdTest() {
        int[] nums = {-7,-3,2,11};
        int[] expected = {4,9,49,121};
        int[] actual = sortedSquares(nums);
        Assertions.assertArrayEquals(expected, actual);
    }
}
