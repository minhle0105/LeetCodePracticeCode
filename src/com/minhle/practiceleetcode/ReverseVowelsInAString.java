package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashSet;
import java.util.Set;

public class ReverseVowelsInAString {
    public String reverseVowels(String s) {
        if (s.length() == 0 || s.length() == 1) {
            return s;
        }
        char[] sToChar = s.toCharArray();
        int leftPointer = 0;
        int rightPointer = s.length() - 1;
        Set<Character> vowels = new HashSet<>();
        vowels.add('u');
        vowels.add('U');
        vowels.add('e');
        vowels.add('E');
        vowels.add('o');
        vowels.add('O');
        vowels.add('a');
        vowels.add('A');
        vowels.add('i');
        vowels.add('I');
        while (leftPointer <= rightPointer) {
            if (!Character.isLetter(sToChar[leftPointer])) {
                leftPointer++;
                continue;
            }
            if (!Character.isLetter(sToChar[rightPointer])) {
                rightPointer--;
                continue;
            }
            if (vowels.contains(sToChar[leftPointer]) && vowels.contains(sToChar[rightPointer])) {
                char temp = sToChar[leftPointer];
                sToChar[leftPointer] = sToChar[rightPointer];
                sToChar[rightPointer] = temp;
                leftPointer++;
                rightPointer--;
            }
            else if (vowels.contains(sToChar[leftPointer])) {
                while (!vowels.contains(sToChar[rightPointer])) {
                    rightPointer--;
                }
            }
            else if (vowels.contains(sToChar[rightPointer])) {
                while (!vowels.contains(sToChar[leftPointer])) {
                    leftPointer++;
                }
            }
            else {
                leftPointer++;
                rightPointer--;
            }
        }
        StringBuilder result = new StringBuilder();
        for (char c : sToChar) {
            result.append(c);
        }
        return result.toString();
    }

    @Test
    void firstTest() {
        String s = "hello";
        String expected = "holle";
        String actual = reverseVowels(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String s = "leetcode";
        String expected = "leotcede";
        String actual = reverseVowels(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void lowerCaseTest() {
        String s = "aA";
        String expected = "Aa";
        String actual = reverseVowels(s);
        Assertions.assertEquals(expected, actual);
    }
}
