package com.minhle.practiceleetcode;

import java.util.Stack;

public class ParenthesesValidation {
      public boolean isValid(String s) {
            Stack<Character> parentheses = new Stack<>();

            for (int i = 0; i < s.length(); i++) {
                  if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') {
                        parentheses.push(s.charAt(i));
                  } else if (!parentheses.isEmpty() &&
                              (
                              (s.charAt(i) == ')' && parentheses.peek() == '(') || 
                              (s.charAt(i) == '}' && parentheses.peek() == '{') ||
                              (s.charAt(i) == ']' && parentheses.peek() == '[')
                              )) {
                        parentheses.pop();
                  } else {
                        parentheses.push(s.charAt(i));
                  }
            }
            return parentheses.isEmpty();
      }
}
