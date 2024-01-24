package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class PascalTriangle {
    public List<List<Integer>> generate(int numRows) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        if (numRows == 1) {
            ArrayList<Integer> list1 = new ArrayList<>();
            list1.add(1);
            result.add(list1);
            return (List) result;
        }
        if (numRows == 2) {
            ArrayList<Integer> list1 = new ArrayList<>();
            list1.add(1);
            list1.add(1);
            result.add(list1);
            return (List) result;
        }
        else {
            ArrayList<Integer> list1 = new ArrayList<>();
            list1.add(1);
            result.add(list1);
            ArrayList<Integer> list2 = new ArrayList<>();
            list2.add(1);
            list2.add(1);
            result.add(list2);
            for (int i = 3; i <= numRows; i++) {
                ArrayList<Integer> thisRow = new ArrayList<>();
                for (int val = 0; val < i; val ++) {
                    thisRow.add(0);
                }
                thisRow.set(0, 1);
                thisRow.set(i - 1, 1);
                for (int j = 1; j < i - 1; j++) {
                    int valueToAdd1 = result.get(i-2).get(j-1);
                    int valueToAdd2 = result.get(i-2).get(j);
                    int valueToAdd = valueToAdd1 + valueToAdd2;
                    thisRow.set(j, valueToAdd);
                }
                result.add(thisRow);
            }
        }
        return (List) result;
    }


    @Test
    void secondTest() {
        int numRows = 1;
        List<List<Integer>> expected = new ArrayList<>();
        List<Integer> list1 = new ArrayList<>();
        list1.add(1);
        expected.add(list1);
        List<List<Integer>> actual = generate(numRows);
        Assertions.assertEquals(expected, actual);
    }


}
