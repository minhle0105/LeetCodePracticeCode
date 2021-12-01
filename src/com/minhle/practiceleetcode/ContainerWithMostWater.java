package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ContainerWithMostWater {

    public int maxArea(int[] height) {
        int leftPointer = 0;
        int rightPointer = height.length - 1;
        int currentMax = -1;
        while (leftPointer < rightPointer) {
            int currentArea = Math.min(height[leftPointer], height[rightPointer]) * (rightPointer - leftPointer);
            if (currentArea > currentMax) {
                currentMax = currentArea;
            }
            else {
                if (height[leftPointer] < height[rightPointer]) {
                    leftPointer++;
                }
                else {
                    rightPointer--;
                }
            }

        }
        return currentMax;
    }

    @Test
    void firstTest() {
        int[] height = {1,8,6,2,5,4,8,3,7};
        int expected = 49;
        int actual = maxArea(height);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[] height = {4,3,2,1,4};
        int expected = 16;
        int actual = maxArea(height);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void thirdTest() {
        int[] height = {1,1};
        int expected = 1;
        int actual = maxArea(height);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void lastTest() {
        int[] height = {1,2,1};
        int expected = 2;
        int actual = maxArea(height);
        Assertions.assertEquals(expected, actual);
    }
}
