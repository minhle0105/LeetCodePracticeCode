package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Stack;

public class ReverseInteger {
      public int reverse(int x) {
            Stack<Character> intStack = new Stack<Character>();
            int xAbsolute = Math.abs(x);
            StringBuilder xString = new StringBuilder(Integer.toString(xAbsolute));
            int xStringLength = xString.length();
            // String xStringReverse = "";
            for (int i = 0; i < xString.length(); i++) {
                  intStack.push(xString.charAt(i));
            }
            xString = new StringBuilder();
            for (int i = 0; i < xStringLength; i++) {
                  xString.append(intStack.pop());
            }
            try {
                  int xReverse = Integer.parseInt(xString.toString());
                  if (x < 0) {
                        return -xReverse;
                  }
                  return xReverse;
            }
            catch (NumberFormatException e) {
                  return 0;
            }
      }

      @Test
      void firstTest() {
            int expected = 321;
            int actual = reverse(123);
            Assertions.assertEquals(expected, actual);
      }

      @Test
      void secondTest() {
            int expected = -321;
            int actual = reverse(-123);
            Assertions.assertEquals(expected, actual);
      }

      @Test
      void zeroTest() {
            int expected = 0;
            int actual = reverse(0);
            Assertions.assertEquals(expected, actual);
      }

      @Test
      void specialZeroTest() {
            int expected = 21;
            int actual = reverse(120);
            Assertions.assertEquals(expected, actual);
      }
}
