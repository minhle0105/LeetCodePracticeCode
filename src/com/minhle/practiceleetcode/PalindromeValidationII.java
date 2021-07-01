package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class PalindromeValidationII {

    public boolean isPalindromeUsingLoops(String s) {
        s = s.replaceAll("\\s+","");
        s = s.replaceAll("[^a-z0-9A-Z]", "");
        s = s.toLowerCase();
        for (int i = 0; i < s.length()/2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public boolean isPalindrome(String s) {
        s = s.replaceAll("\\s+","");
        s = s.replaceAll("[^a-z0-9A-Z]", "");
        s = s.toLowerCase();
        Stack<Character> stack = new Stack<>();
        Queue<Character> queue = new LinkedList<>();
        for (int i = 0; i < s.length()/2; i++) {
            stack.push(s.charAt(i));
        }
        int j;
        if (s.length()%2 == 0) {
            j = s.length()/2;
        }
        else {
            j = (s.length()/2) + 1;
        }
        for (int i = j; i < s.length(); i++) {
            queue.add(s.charAt(i));
        }

        while (!stack.isEmpty()) {
            if (stack.peek() != queue.peek()) {
                return false;
            }
            stack.pop();
            queue.remove();
        }
        return true;
    }

    public boolean validPalindrome(String s) {
        if (isPalindrome(s)) {
            return true;
        }
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            char b = s.charAt(s.length() - i - 1);
            if (a != b) {
                String testString1 = s.substring(0, i) +
                        s.substring(i + 1);
                String testString2 = s.substring(0, s.length() - i - 1) + s.substring(s.length() - i);
                return isPalindrome(testString1) | isPalindrome(testString2);
            }
        }
        return true;
    }

    @Test
    void firstTest() {
        String s = "aba";
        Assertions.assertTrue(validPalindrome(s));
    }

    @Test
    void secondTest() {
        String s = "abca";
        Assertions.assertTrue(validPalindrome(s));
    }

    @Test
    void lastTest() {
        String s = "abc";
        Assertions.assertFalse(validPalindrome(s));
    }

    @Test
    void failedTest() {
        String s = "eddze";
        Assertions.assertTrue(validPalindrome(s));
    }
}
