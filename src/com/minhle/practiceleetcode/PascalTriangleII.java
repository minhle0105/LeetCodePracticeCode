package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class PascalTriangleII {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<>();
        result.add(1);
        if (rowIndex == 0) {
            return result;
        }
        if (rowIndex == 1) {
            result.add(1);
            return result;
        }
        else {
            result.add(1);
            return calculatePascal(rowIndex, result);
        }

    }

    private List<Integer> calculatePascal(int rowIndex, List<Integer> previousRow) {
        List<Integer> result = new ArrayList<>();
        int currentRow = previousRow.size() - 1;
        if (currentRow < rowIndex) {
            result.add(1);
            for (int i = 1; i < previousRow.size(); i++) {
                result.add(previousRow.get(i) + previousRow.get(i-1));
            }
            result.add(1);
            return calculatePascal(rowIndex, result);
        }
        else {
            return previousRow;
        }
    }

    @Test
    void firstTest() {
        int rowIndex = 4;
        int[] n = {1,4,6,4,1};
        List<Integer> expected = new ArrayList<>();
        for (int i : n) {
            expected.add(i);
        }
        List<Integer> actual = getRow(rowIndex);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void edgeCase() {
        int rowIndex = 0;
        int[] n = {1};
        List<Integer> expected = new ArrayList<>();
        for (int i : n) {
            expected.add(i);
        }
        List<Integer> actual = getRow(rowIndex);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void edgeCase2() {
        int rowIndex = 1;
        int[] n = {1,1};
        List<Integer> expected = new ArrayList<>();
        for (int i : n) {
            expected.add(i);
        }
        List<Integer> actual = getRow(rowIndex);
        Assertions.assertEquals(expected, actual);
    }
}
