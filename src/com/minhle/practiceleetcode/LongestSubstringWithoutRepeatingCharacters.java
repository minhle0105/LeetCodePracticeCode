package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class LongestSubstringWithoutRepeatingCharacters {
    private boolean containsDuplicateChar(String s) {
        if (s.length() == 1) {
            return false;
        }
        HashMap<Character, Integer> hashMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            if (hashMap.containsKey(c)) {
                return true;
            }
            else {
                hashMap.put(c, 1);
            }
        }
        return false;
    }
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0 || s.length() == 1) {
            return s.length();
        }
        int result = 0;
        int maxLength = 0;
        int right = 0;
        int left = 0;
        while (right < s.length()) {
            String sub = s.substring(left, right + 1);
            if (!containsDuplicateChar(sub)) {
                right++;
                result = sub.length();
                if (result > maxLength) {
                    maxLength = result;
                }
            }
            else {
                left++;

            }

        }
        return maxLength;
    }

    @Test
    void firstTest() {
        String s = "abcabcbb";
        int expected = 5;
        int actual = lengthOfLongestSubstring(s);
        Assertions.assertEquals(expected, actual);

    }
}