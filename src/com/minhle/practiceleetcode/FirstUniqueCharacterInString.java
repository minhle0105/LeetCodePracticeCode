package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class FirstUniqueCharacterInString {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if (hashMap.containsKey(s.charAt(i))) {
                hashMap.put(s.charAt(i), hashMap.get(s.charAt(i)) + 1);
            }
            else {
                hashMap.put(s.charAt(i), 1);
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (hashMap.get(s.charAt(i)) == 1) {
                return i;
            }
        }
        return -1;
    }

    @Test
    void firstTest() {
        int expected = 0;
        int actual = firstUniqChar("leetcode");
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int expected = 2;
        int actual = firstUniqChar("loveleetcode");
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void lastTest() {
        int expected = -1;
        int actual = firstUniqChar("aabb");
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failTest() {
        int expected = 0;
        int actual = firstUniqChar("z");
        Assertions.assertEquals(expected, actual);
    }
}
