package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class StringToInteger {
    public int myAtoi(String s) {
        s = s.trim();
        String[] words = s.split(" ");
        for (String word : words) {
            if (Character.isDigit(word.charAt(word.length() - 1))) {
                return convert(word);
            }
        }
        return -1;
    }

    private int convert(String s) {
        if (s.charAt(0) == '-') {
            return Integer.parseInt(s.substring(1)) * -1;
        }
        return Integer.parseInt(s);
    }

    @Test
    void firstTest() {
        String s = "42";
        int expected = 42;
        int actual = myAtoi(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String s = "       -42";
        int expected = -42;
        int actual = myAtoi(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        String s = "4193 with words";
        int expected = 4193;
        int actual = myAtoi(s);
        Assertions.assertEquals(expected, actual);
    }
    @Test
    void test4() {
        String s = "words and 987";
        int expected = 987;
        int actual = myAtoi(s);
        Assertions.assertEquals(expected, actual);
    }
}
