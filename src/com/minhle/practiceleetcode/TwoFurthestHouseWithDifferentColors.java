package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class TwoFurthestHouseWithDifferentColors {

    public int maxDistance(int[] colors) {
        return Math.max(getFromLeftToRight(colors), getFromRightToLeft(colors));
    }

    private int getFromLeftToRight(int[] colors) {
        int firstColorFromLeft = colors[0];
        int pointerFromRight = colors.length - 1;
        while (colors[pointerFromRight] == firstColorFromLeft) {
            pointerFromRight--;
        }
        return pointerFromRight;
    }

    private int getFromRightToLeft(int[] colors) {
        int firstColorFromRight = colors[colors.length - 1];
        int pointerFromLeft = 0;
        while (colors[pointerFromLeft] == firstColorFromRight) {
            pointerFromLeft++;
        }
        return colors.length - pointerFromLeft - 1;
    }

    @Test
    void firstTest() {
        int[] colors = {1,1,1,6,1,1,1};
        int expected = 3;
        int actual = maxDistance(colors);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[] colors = {1,8,3,8,3};
        int expected = 4;
        int actual = maxDistance(colors);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void lastTest() {
        int[] colors = {0, 1};
        int expected = 1;
        int actual = maxDistance(colors);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest() {
        int[] colors = {100, 0};
        int expected = 1;
        int actual = maxDistance(colors);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest2() {
        int[] colors = {4,4,4,11,4,4,11,4,4,4,4,4};
        int expected = 8;
        int actual = maxDistance(colors);
        Assertions.assertEquals(expected, actual);
    }
}
