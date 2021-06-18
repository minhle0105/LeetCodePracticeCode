package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.LinkedHashMap;
import java.util.Map;

public class FirstUniqueCharacterInString {
    public int firstUniqChar(String s) {
        LinkedHashMap<Character, Integer> hashMap = new LinkedHashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if (!hashMap.containsKey(s.charAt(i))) {
                hashMap.put(s.charAt(i), 1);
            }
            else {
                hashMap.put(s.charAt(i), hashMap.get(s.charAt(i)) + 1);
            }
        }
        for (Map.Entry mapElement : hashMap.entrySet()) {
            if ((Integer) mapElement.getValue() == 1) {
                return s.indexOf((Character) mapElement.getKey());
            }
        }
        return -1;
    }

    @Test
    void firstTest() {
        int expected = 0;
        int actual = firstUniqChar("leetcode");
    }

    @Test
    void secondTest() {
        int expected = 2;
        int actual = firstUniqChar("loveleetcode");
    }

    @Test
    void lastTest() {
        int expected = -1;
        int actual = firstUniqChar("aabb");
    }
}
