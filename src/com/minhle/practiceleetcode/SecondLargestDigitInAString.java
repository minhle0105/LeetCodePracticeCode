package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class SecondLargestDigitInAString {
    public int secondHighest(String s) {
        Set<Integer> nums = new HashSet<>();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                int i = Integer.parseInt(String.valueOf(c));
                nums.add(i);
            }
        }
        List<Integer> numsList = new ArrayList<>(nums);
        Collections.sort(numsList);
        try {
            return numsList.get(numsList.size() - 2);
        }
        catch (Exception e) {
            return -1;
        }
    }

    @Test
    void firstTest() {
        String s = "dfa12321afd";
        int expected = 2;
        int actual = secondHighest(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String s = "abc1111";
        int expected = -1;
        int actual = secondHighest(s);
        Assertions.assertEquals(expected, actual);
    }
}
