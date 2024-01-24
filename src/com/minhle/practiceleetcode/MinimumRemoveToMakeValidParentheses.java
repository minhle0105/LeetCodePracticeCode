package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class MinimumRemoveToMakeValidParentheses {
    public String minRemoveToMakeValid(String s) {
        Stack<Character> stack = new Stack<>();
        Stack<Integer> indexStack = new Stack<>();
        Set<Integer> invalidPosition = new HashSet<>();
        StringBuilder sBuilder = new StringBuilder("");
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                if (!stack.isEmpty() && stack.peek() == '(') {
                    stack.pop();
                    indexStack.pop();
                }
                else {
                    invalidPosition.add(i);
                }
            }
            else if (s.charAt(i) == '(') {
                stack.push(s.charAt(i));
                indexStack.push(i);
            }
        }
        while (!indexStack.empty()) {
            invalidPosition.add(indexStack.pop());
        }
        for (int i = 0; i < s.length(); i++) {
            if (!invalidPosition.contains(i)) {
                sBuilder.append(s.charAt(i));
            }
        }
        return sBuilder.toString();
    }

    @Test
    void test1() {
        String s = "))((";
        String expected = "";
        String actual = minRemoveToMakeValid(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        String s = "a)b(c)d";
        String expected = "ab(c)d";
        String actual = minRemoveToMakeValid(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        String s = "lee(t(c)o)de)";
        String expected = "lee(t(c)o)de";
        String actual = minRemoveToMakeValid(s);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failTest() {
        String s = "(a(b(c)d)";
        String expected = "a(b(c)d)";
        String actual = minRemoveToMakeValid(s);
        Assertions.assertEquals(expected, actual);
    }
}
