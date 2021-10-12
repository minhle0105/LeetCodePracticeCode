package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class RansomNote {
    public boolean canConstruct(String ransomNote, String magazine) {
        if (ransomNote.length() == 1 && magazine.length() == 1) {
            return ransomNote.equals(magazine);
        }
        if (ransomNote.length() == 0) {
            return true;
        }
        if (magazine.indexOf(ransomNote.charAt(0)) >= 0) {
            char c = ransomNote.charAt(0);
            return canConstruct(ransomNote.replaceFirst(String.valueOf(c), ""), magazine.replaceFirst(String.valueOf(c), ""));
        }
        return false;
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
}
