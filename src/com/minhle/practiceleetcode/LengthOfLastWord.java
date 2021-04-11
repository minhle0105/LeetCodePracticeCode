package com.minhle.practiceleetcode;

public class LengthOfLastWord {
      public static int solution(String s) {
            if (s.length() == 0 || s.equals(" ")) {
                  return 0;
            }
            int lastWordLength = 0;
            boolean beforeFirstNonEmpty = true;
            for (int i = s.length() - 1; i >= 0; i--) {
                  if (s.charAt(i) != ' ') {
                        lastWordLength++;
                        beforeFirstNonEmpty = false;
                  } else if (!beforeFirstNonEmpty) {
                        break;
                  }
            }
            return lastWordLength;
      }
}
