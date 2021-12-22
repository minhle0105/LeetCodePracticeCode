package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Stack;

public class EvalsReversePolishNotation {
    public int evalRPN(String[] tokens) {
        Stack<String> stack = new Stack<>();
        for (String token : tokens) {
            if (stack.size() >= 2 && token.equals("+")) {
                int a = Integer.parseInt(stack.pop());
                int b = Integer.parseInt(stack.pop());
                int aPlusB = a + b;
                stack.push(aPlusB+"");
            }
            else if (stack.size() >= 2 && token.equals("-")) {
                int a = Integer.parseInt(stack.pop());
                int b = Integer.parseInt(stack.pop());
                int aMinusB = b - a;
                stack.push(aMinusB+"");
            }
            else if (stack.size() >= 2 && token.equals("*")) {
                int a = Integer.parseInt(stack.pop());
                int b = Integer.parseInt(stack.pop());
                int aMultiplyB = a * b;
                stack.push(aMultiplyB+"");
            }
            else if (stack.size() >= 2 && token.equals("/")) {
                int a = Integer.parseInt(stack.pop());
                int b = Integer.parseInt(stack.pop());
                int aDividesB = b / a;
                stack.push(aDividesB+"");
            }
            else {
                stack.push(token);
            }
        }
        return Integer.parseInt(stack.pop());
    }
    @Test
    void firstTest() {
        String[] tokens = {"2","1","+","3","*"};
        int expected = 9;
        int actual = evalRPN(tokens);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String[] tokens = {"4","13","5","/","+"};
        int expected = 6;
        int actual = evalRPN(tokens);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void thirdTest() {
        String[] tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
        int expected = 22;
        int actual = evalRPN(tokens);
        Assertions.assertEquals(expected, actual);
    }

}
