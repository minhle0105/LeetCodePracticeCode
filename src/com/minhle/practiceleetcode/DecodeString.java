package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Stack;

public class DecodeString {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c != ']') {
                stack.push(c);
            }
            else {
                StringBuilder word = new StringBuilder();
                while (!stack.isEmpty() && Character.isLetter(stack.peek())) {
                    word.append(stack.pop());
                }
                // pop '['
                stack.pop();

                StringBuilder countString = new StringBuilder();
                while (!stack.isEmpty() && Character.isDigit(stack.peek())) {
                    countString.append(stack.pop());
                }
                int count = Integer.parseInt(reverse(countString));
                StringBuilder decodedWord = new StringBuilder();
                for (int i = 0; i < count; i++) {
                    decodedWord.append(word);
                }
                String rev = reverse(decodedWord);
                for (char ch : rev.toCharArray()) {
                    stack.push(ch);
                }
            }
        }
        StringBuilder resultRev = new StringBuilder();
        while (!stack.isEmpty()) {
            resultRev.append(stack.pop());
        }
        String finalResult = reverse(resultRev);
        return finalResult;
    }

    private String reverse(StringBuilder word) {
        StringBuilder rev = new StringBuilder();
        for (int i = word.toString().length() - 1; i >= 0; i--) {
            rev.append(word.charAt(i));
        }
        return rev.toString();
    }

    @Test
    void test1() {
        String s = "3[a2[c]]";
        String expected = "accaccacc";
        String actual = decodeString(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        String s = "3[a]2[bc]";
        String expected = "aaabcbc";
        String actual = decodeString(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        String s = "10[a]";
        String expected = "aaaaaaaaaa";
        String actual = decodeString(s);
        Assertions.assertEquals(expected, actual);
    }
}
