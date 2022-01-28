package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class StringToInteger {
    public int myAtoi(String s) {
        s = s.trim();
        String[] strings = s.split(" ");
        s = strings[0].trim();
        StringBuilder str = new StringBuilder();
        int firstInteger;

        if (s.charAt(0) == '-') {
            firstInteger = 1;
            if (s.charAt(firstInteger) != '0') {
                for (int i = 0; i < s.length(); i++) {
                    str.append(s.charAt(i));
                }
            }
            else {
                for (int i = 1; i < s.length(); i++) {
                    if (s.charAt(i) != '0') {
                        firstInteger = i;
                        break;
                    }
                }
                for (int i = firstInteger; i < s.length(); i++) {
                    str.append(s.charAt(i));
                }
            }
        }
        else {
            firstInteger = 0;
            if (s.charAt(firstInteger) != '0') {
                for (int i = 0; i < s.length(); i++) {
                    str.append(s.charAt(i));
                }
            }
            else {
                for (int i = 0; i < s.length(); i++) {
                    if (s.charAt(i) != '0') {
                        firstInteger = i;
                        break;
                    }
                }
                for (int i = firstInteger; i < s.length(); i++) {
                    str.append(s.charAt(i));
                }
            }
        }
        return Integer.parseInt(str.toString());
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
}
