package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class PalindromeValidation {
      public boolean isPalindrome(String s) {
            s = s.replaceAll("\\s+","");
            s = s.replaceAll("[^a-z0-9A-Z]", "");
            s = s.toLowerCase();
            Stack<Character> stack = new Stack<>();
            Queue<Character> queue = new LinkedList<>();
            for (int i = 0; i < s.length(); i++) {
                  stack.push(s.charAt(i));
                  queue.add(s.charAt(i));
            }
            for (int i = 0; i < s.length(); i++) {
                  if (stack.peek() != queue.peek()) {
                        return false;
                  }
                  stack.pop();
                  queue.remove();
            }
            return true;
      }
}
