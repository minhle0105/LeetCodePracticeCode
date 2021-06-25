package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class EquivalentStringArrays {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        StringBuilder word1ToString = new StringBuilder();
        StringBuilder word2ToString = new StringBuilder();
        for (String s : word1) {
            word1ToString.append(s);
        }
        for (String s : word2) {
            word2ToString.append(s);
        }
        return word1ToString.toString().equals(word2ToString.toString());
    }

    @Test
    void firstTest() {
        String[] word1 = {"ab", "c"};
        String[] word2 = {"a", "bc"};
        Assertions.assertTrue(arrayStringsAreEqual(word1, word2));
    }

    @Test
    void secondTest() {
        String[] word1 = {"a", "cb"};
        String[] word2 = {"ab", "c"};
        Assertions.assertFalse(arrayStringsAreEqual(word1, word2));
    }

    @Test
    void lastTest() {
        String[] word1 = {"abc", "d", "defg"};
        String[] word2 = {"abcddefg"};
        Assertions.assertTrue(arrayStringsAreEqual(word1, word2));
    }
}
