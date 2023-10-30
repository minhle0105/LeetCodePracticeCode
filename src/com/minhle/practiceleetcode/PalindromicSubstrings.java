package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class PalindromicSubstrings {
    public int countSubstrings(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (isPalindrome(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }

    private boolean isPalindrome(String s, int low, int high) {
        while (low <= high) {
            if (s.charAt(low) != s.charAt(high)) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }

    @Test
    void test() {
        String s1 = "abc";
        int expected1 = 3;
        int actual1 = countSubstrings(s1);
        String s2 = "aaa";
        int expected2 = 6;
        int actual2 = countSubstrings(s2);
        Assertions.assertTrue(expected1 == actual1 & expected2 == actual2);
    }
}
