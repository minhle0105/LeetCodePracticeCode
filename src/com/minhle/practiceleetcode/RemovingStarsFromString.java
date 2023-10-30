package com.minhle.practiceleetcode;

import java.util.*;
public class RemovingStarsFromString {
    public String removeStars(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && c == '*') {
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }
        Stack<Character> rev = new Stack<>();
        while (!stack.isEmpty()) {
            rev.push(stack.pop());
        }
        StringBuilder res = new StringBuilder();
        while (!rev.isEmpty()) {
            res.append(rev.pop());
        }
        return res.toString();
    }
}
