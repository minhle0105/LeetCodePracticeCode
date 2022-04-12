package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashSet;
import java.util.Set;

public class LongestSubstringWithoutRepeatingCharacters {

    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int leftPointer = 0;
        int rightPointer = 0;
        int result = 0;
        while (rightPointer < s.length()) {
            while (set.contains(s.charAt(rightPointer))) {
                set.remove(s.charAt(leftPointer));
                leftPointer++;
            }
            set.add(s.charAt(rightPointer));
            rightPointer++;
            result = Math.max(result, rightPointer - leftPointer);
        }
        return result;
    }

    @Test
    void firstTest() {
        String s = "abcabcbb";
        int expected = 3;
        int actual = lengthOfLongestSubstring(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String s = "bbbbb";
        int expected = 1;
        int actual = lengthOfLongestSubstring(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void lastTest() {
        String s = "pwwkew";
        int expected = 3;
        int actual = lengthOfLongestSubstring(s);
        Assertions.assertEquals(expected, actual);
    }
}