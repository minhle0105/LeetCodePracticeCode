package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class LongestCommonPrefix {
    public static String solution(String[] strs) {
        if (strs.length == 1) {
            return strs[0];
        }
        if (strs.length == 0) {
            return "";
        }
        for (String s : strs) {
            if (s.length() == 0) {
                return "";
            }
        }
        for (int i = 0; i < strs[0].length(); i++) {
            char currentChar = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (i >= strs[j].length() || strs[j].charAt(i) != currentChar) {
                    return strs[0].substring(0,i);
                }
            }
        }
        return strs[0];
    }

    @Test
    void firstTest() {
        String expected = "a";
        String[] strs = {"ab", "a"};
        String actual = solution(strs);
        assertEquals(actual, expected);
    }

    @Test
    void emptyStringTest() {
        String expected = "";
        String[] strs = {"", "a"};
        String actual = solution(strs);
        assertEquals(actual, expected);
    }

    @Test
    void oneCharacterStringTest() {
        String expected = "flower";
        String[] strs = {"flower", "flower"};
        String actual = solution(strs);
        assertEquals(expected, actual);
    }

    @Test
    void oneElementString() {
        String expected = "a";
        String[] strs = {"a"};
        String actual = solution(strs);
        assertEquals(expected, actual);
    }

}
