package com.minhle.practiceleetcode;

import java.util.Stack;

public class ReverseInteger {
      public int reverse(int x) {
            Stack<Character> intStack = new Stack<Character>();
            int xAbsolute = Math.abs(x);
            String xString = Integer.toString(xAbsolute);
            int xStringLength = xString.length();
            // String xStringReverse = "";
            for (int i = 0; i < xString.length(); i++) {
                  intStack.push(xString.charAt(i));
            }
            xString = "";
            for (int i = 0; i < xStringLength; i++) {
                  xString += intStack.pop();
            }
            try {
                  int xReverse = Integer.parseInt(xString);
                  if (x < 0) {
                        return -xReverse;
                  } 
                  return xReverse;
            }
            catch (NumberFormatException e) {
                  return 0;
            }
      }
}
