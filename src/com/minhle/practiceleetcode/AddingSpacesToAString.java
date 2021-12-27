package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AddingSpacesToAString {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder result = new StringBuilder();
        int currentSpacePointer = 0;
        for (int i = 0; i < s.length();) {
            if (currentSpacePointer < spaces.length && i == spaces[currentSpacePointer]) {
                result.append(" ");
                currentSpacePointer++;
            }
            else {
                result.append(s.charAt(i));
                i++;
            }
        }
        return result.toString();
    }

    @Test
    void firstTest() {
        String s = "LeetcodeHelpsMeLearn";
        int[] spaces = {8, 13, 15};
        String expected = "Leetcode Helps Me Learn";
        String actual = addSpaces(s, spaces);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String s = "icodeinpython";
        int[] spaces = {1, 5, 7, 9};
        String expected = "i code in py thon";
        String actual = addSpaces(s, spaces);
        Assertions.assertEquals(expected, actual);
    }
}
