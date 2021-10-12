package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;

public class RansomNote {
    private static HashMap<Character, Integer> getCharFrequency(String s) {
        HashMap<Character, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if (hashMap.containsKey(s.charAt(i))) {
                hashMap.put(s.charAt(i), hashMap.get(s.charAt(i)) + 1);
            }
            else {
                hashMap.put(s.charAt(i), 1);
            }
        }
        return hashMap;
    }
    public boolean canConstruct(String ransomNote, String magazine) {
        if (ransomNote.length() == 1 && magazine.length() == 1) {
            return ransomNote.equals(magazine);
        }
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        HashMap<Character, Integer> ransomNoteCount = getCharFrequency(ransomNote);
        HashMap<Character, Integer> magazineCount = getCharFrequency(magazine);
        for (int i = 0; i < ransomNote.length(); i++) {
            if (!(magazineCount.containsKey(ransomNote.charAt(i)))) {
                return false;
            }
            else {
                if (!(ransomNoteCount.get(ransomNote.charAt(i)) <= magazineCount.get(ransomNote.charAt(i)))) {
                    return false;
                }
            }
        }
        return true;

    }

    @Test
    void firstTest() {
        String ransomNote = "a";
        String magazine = "b";
        Assertions.assertFalse(canConstruct(ransomNote, magazine));
    }

    @Test
    void secondTest() {
        String ransomNote = "aa";
        String magazine = "ab";
        Assertions.assertFalse(canConstruct(ransomNote, magazine));
    }

    @Test
    void thirdTest() {
        String ransomNote = "aa";
        String magazine = "aba";
        Assertions.assertTrue(canConstruct(ransomNote, magazine));
    }

    @Test
    void failTest() {
        String ransomNote = "az";
        String magazine = "ab";
        Assertions.assertFalse(canConstruct(ransomNote, magazine));
    }
}
