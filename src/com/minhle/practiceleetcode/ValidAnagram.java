package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class ValidAnagram {
    private HashMap<Character, Integer> getFrequencyOfChar(String s) {
        HashMap<Character, Integer> hashMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            if (hashMap.containsKey(c)) {
                hashMap.put(c, hashMap.get(c) + 1);
            }
            else {
                hashMap.put(c, 1);
            }
        }
        return hashMap;
    }
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        HashMap<Character, Integer> sCount = getFrequencyOfChar(s);
        HashMap<Character, Integer> tCount = getFrequencyOfChar(t);
        for (char c : s.toCharArray()) {
            if (!sCount.get(c).equals(tCount.get(c))) {
                return false;
            }
        }
        return true;
    }

    @Test
    void failTest() {
        String s = "abca";
        String t = "bcaa";
        Assertions.assertTrue(isAnagram(s, t));
    }
}
