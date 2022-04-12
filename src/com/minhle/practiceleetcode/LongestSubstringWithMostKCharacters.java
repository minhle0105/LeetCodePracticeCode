package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class LongestSubstringWithMostKCharacters {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int n = s.length();
        if (n * k == 0) {
            return 0;
        }
        Map<Character, Integer> map = new HashMap<>();
        int left = 0;
        int right = 0;
        int max = 1;
        while (right < n) {
            map.put(s.charAt(right), right);
            right++;
            if (map.size() > k) {
                int removedIndex = Collections.min(map.values());
                map.remove(s.charAt(removedIndex));
                left = removedIndex + 1;
            }
            max = Math.max(max, right - left);
        }
        return max;
    }

    @Test
    void test1() {
        String s = "eceba";
        int k = 2;
        int expected = 3;
        int actual = lengthOfLongestSubstringKDistinct(s, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        String s = "aa";
        int k = 1;
        int expected = 2;
        int actual = lengthOfLongestSubstringKDistinct(s, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        String s = "abaccc";
        int k = 2;
        int expected = 4;
        int actual = lengthOfLongestSubstringKDistinct(s, k);
        Assertions.assertEquals(expected, actual);
    }
}
