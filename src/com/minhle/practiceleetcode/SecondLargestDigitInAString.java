package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;


public class SecondLargestDigitInAString {
    public int secondHighest(String s) {
        int largest = -1;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                int i = Integer.parseInt(String.valueOf(c));
                if (i > largest) {
                    largest = i;
                }
            }
        }

        int secondLargest = -1;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                int i = Integer.parseInt(String.valueOf(c));
                if (i > secondLargest && i != largest) {
                    secondLargest = i;
                }
            }
        }
        return secondLargest;
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
