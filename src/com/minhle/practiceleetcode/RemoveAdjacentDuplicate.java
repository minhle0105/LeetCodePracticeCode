package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class RemoveAdjacentDuplicate {
    public String removeDuplicates(String s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i+1)) {
                String duplicateCharacters = String.valueOf(s.charAt(i));
                duplicateCharacters += String.valueOf(s.charAt(i+1));
                s = s.replaceFirst(duplicateCharacters, "");
                i = -1;
            }
        }
        return s;
    }

    @Test
    void firstTest() {
        String expected = "ca";
        String actual = removeDuplicates("abbaca");
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String expected = "ay";
        String actual = removeDuplicates("azxxzy");
        Assertions.assertEquals(expected, actual);
    }
}
