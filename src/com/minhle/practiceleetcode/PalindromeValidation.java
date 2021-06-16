package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
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

      @Test
      void firstTest() {
            boolean expected = true;
            String s = "A man, a plan, a canal: Panama";
            boolean actual = isPalindrome(s);
            assertEquals(expected, actual);
      }

      @Test
      void secondTest() {
            boolean expected = false;
            String s = "race a car";
            boolean actual = isPalindrome(s);
            assertEquals(expected, actual);
      }

      @Test
      void lastTest() {
            boolean expected = false;
            String s = "abc";
            boolean actual = isPalindrome(s);
            assertEquals(expected, actual);
      }

      @Test
      void failedTest() {
            boolean expected = true;
            String s = "aa";
            boolean actual = isPalindrome(s);
            assertEquals(expected, actual);
      }
}
