package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class DetectCapital {
    public boolean detectCapitalUse(String word) {
        if (word.toUpperCase().equals(word) || word.toLowerCase().equals(word)) {
            return true;
        }
        boolean firstLetterCap = word.charAt(0) == Character.toUpperCase(word.charAt(0));
        int numberOfCapLetters = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == Character.toUpperCase(word.charAt(i))) {
                numberOfCapLetters++;
            }
        }

        return numberOfCapLetters == 1 && firstLetterCap;
    }

    @Test
    void firstTest() {
        boolean expected = true;
        boolean actual = detectCapitalUse("USA");
        assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        boolean expected = false;
        boolean actual = detectCapitalUse("FlaG");
        assertEquals(expected, actual);
    }

    @Test
    void thirdTest() {
        boolean expected = true;
        boolean actual = detectCapitalUse("leetcode");
        assertEquals(expected, actual);
    }

    @Test
    void lastTest() {
        boolean expected = true;
        boolean actual = detectCapitalUse("Google");
        assertEquals(expected, actual);
    }
}
