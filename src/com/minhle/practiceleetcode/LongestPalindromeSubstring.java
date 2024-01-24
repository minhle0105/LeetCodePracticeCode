package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class LongestPalindromeSubstring {

    public String longestPalindrome(String s) {
        if (s.length() == 1) {
            return s;
        }
        int maxLength = 0;
        String result = "";
        for (int i = 0; i < s.length(); i++) {
            int leftPointer = i;
            int rightPointer = i;
            while (leftPointer >= 0 && rightPointer < s.length() && s.charAt(leftPointer) == s.charAt(rightPointer)) {
                if (rightPointer - leftPointer + 1 > maxLength) {
                    maxLength = rightPointer - leftPointer + 1;
                    result = s.substring(leftPointer, rightPointer + 1);
                }
                leftPointer--;
                rightPointer++;
            }
            leftPointer = i;
            rightPointer = i+1;
            while (leftPointer >= 0 && rightPointer < s.length() && s.charAt(leftPointer) == s.charAt(rightPointer)) {
                if (rightPointer - leftPointer + 1 > maxLength) {
                    maxLength = rightPointer - leftPointer + 1;
                    result = s.substring(leftPointer, rightPointer + 1);
                }
                leftPointer--;
                rightPointer++;
            }
        }
        return result;
    }

    @Test
    void oddTest() {
        String s = "babad";
        String expected1 = "bab";
        String expected2 = "aba";
        String actual = longestPalindrome(s);
        Assertions.assertTrue(actual.equals(expected1) | actual.equals(expected2));

    }

    @Test
    void evenTest() {
        String s = "cbbd";
        String expected = "bb";
        String actual = longestPalindrome(s);
        Assertions.assertEquals(actual, expected);
    }

    @Test
    void lengthOneTest() {
        String s = "a";
        String expected = "a";
        String actual = longestPalindrome(s);
        Assertions.assertEquals(actual, expected);
    }

    @Test
    void emptyStringTest() {
        String s = "";
        String expected = "";
        String actual = longestPalindrome(s);
        Assertions.assertEquals(actual, expected);
    }
}

