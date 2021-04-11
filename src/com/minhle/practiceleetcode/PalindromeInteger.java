package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class PalindromeInteger {
      // check if an int is palindrome
      public static boolean solution1(int x) {
            if (x < 0) {
                  return false;
            }
            Stack<Integer> stack = new Stack<>();
            Queue<Integer> queue = new LinkedList<>();
            int curr = x;
            while (curr != 0) {
                  stack.push(curr % 10);
                  queue.add(curr % 10);
                  curr /= 10;
            }
            while (!stack.isEmpty()) {
                  if (stack.pop() != queue.remove()) {
                        return false;
                  }
            }
            return true;
      }

      public static boolean solution2(int x) {
            if (x < 0) {
                  return false;
            }
            String xString = Integer.toString(x);
            for (int i = 0; i < xString.length() / 2; i++) {
                  if (xString.charAt(i) != xString.charAt(xString.length() - i - 1)) {
                        return false;
                  }
            }
            return true;
      }
}
