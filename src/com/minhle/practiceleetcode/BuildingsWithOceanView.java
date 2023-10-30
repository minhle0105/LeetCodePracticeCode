package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class BuildingsWithOceanView {
    public int[] findBuildings(int[] heights) {
        List<Integer> resultList = new ArrayList<>();
        resultList.add(heights.length - 1);
        int maxVal = heights[heights.length - 1];
        for (int i = heights.length - 1; i > 0; i--) {
            if (heights[i] > maxVal) {
                maxVal = heights[i];
            }
            if (heights[i] < heights[i - 1] && heights[i - 1] > maxVal) {
                resultList.add(i-1);
            }
        }
        int[] result = new int[resultList.size()];
        int count = 0;
        for (int i = result.length - 1; i >= 0; i--) {
            result[count++] = resultList.get(i);
        }
        return result;
    }

    @Test
    void test1() {
        int[] heights = {4,2,3,1};
        int[] expected = {0,2,3};
        int[] actual = findBuildings(heights);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] heights = {4,3,2,1};
        int[] expected = {0,1,2,3};
        int[] actual = findBuildings(heights);
        Assertions.assertArrayEquals(expected, actual);
    }

    @Test
    void test3() {
        int[] heights = {1,3,2,4};
        int[] expected = {3};
        int[] actual = findBuildings(heights);
        Assertions.assertArrayEquals(expected, actual);
    }

}
