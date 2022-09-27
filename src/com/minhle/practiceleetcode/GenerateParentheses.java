package com.minhle.practiceleetcode;


import org.junit.jupiter.api.Test;

import java.util.*;

public class GenerateParentheses {
    Stack<String> stack;
    List<String> res;

    public List<String> generateParenthesis(int n) {
        stack = new Stack<>();
        res = new ArrayList<>();
        backtrack(0,0,n);
        return res;
    }

    private String reverse(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            sb.append(s.charAt(i));
        }
        return sb.toString();
    }

    private String joinStack() {
        StringBuilder sb = new StringBuilder("");
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        String toAdd = reverse(sb.toString());
        for (char c : toAdd.toCharArray()) {
            stack.push(String.valueOf(c));
        }
        return toAdd;
    }
    private void backtrack(int numberOfOpen, int numberOfClose, int n) {
        if (numberOfOpen == numberOfClose && numberOfClose == n) {
            String toAdd = joinStack();
            res.add(toAdd);
            return;
        }
        if (numberOfOpen < n) {
            stack.push("(");
            backtrack(numberOfOpen + 1, numberOfClose, n);
            stack.pop();
        }
        if (numberOfClose < numberOfOpen) {
            stack.push(")");
            backtrack(numberOfOpen, numberOfClose + 1, n);
            stack.pop();
        }
    }

    @Test
    void test1() {
        int n = 2;
        generateParenthesis(n);
    }
}
