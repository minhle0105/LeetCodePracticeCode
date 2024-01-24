package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class CustomNumber implements Comparable<CustomNumber> {
    int value;

    public CustomNumber(int value) {
        this.value = value;
    }

    @Override
    public int compareTo(CustomNumber o) {
        String a = value + "";
        String b = o.value + "";
        long a1 = Long.parseLong(a + b);
        long a2 = Long.parseLong(b + a);
        return Long.compare(a2, a1);
    }
}

public class LargestNumber {
    public String largestNumber(int[] nums) {
        List<CustomNumber> numberList = new ArrayList<>();
        for (int i : nums) {
            CustomNumber c = new CustomNumber(i);
            numberList.add(c);
        }
        Collections.sort(numberList);
        if (numberList.get(0).value == 0) return "0";
        StringBuilder result = new StringBuilder();
        for (CustomNumber c : numberList) {
            result.append(c.value);
        }
        return result.toString();
    }

    @Test
    void test1() {
        int[] nums = {10,2};
        String expected = "210";
        String actual = largestNumber(nums);
        Assertions.assertTrue(expected.equals(actual));
    }

    @Test
    void test2() {
        int[] nums = {3,30,34,5,9};
        String expected = "9534330";
        String actual = largestNumber(nums);
        Assertions.assertTrue(expected.equals(actual));
    }

    @Test
    void test3() {
        int[] nums = {0,0};
        String expected = "0";
        String actual = largestNumber(nums);
        Assertions.assertTrue(expected.equals(actual));
    }
    @Test
    void failedTest() {
        int[] nums = {999999991,9};
        String expected = "9999999991";
        String actual = largestNumber(nums);
        Assertions.assertTrue(expected.equals(actual));
    }
}
