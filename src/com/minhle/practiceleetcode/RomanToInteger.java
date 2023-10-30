package com.minhle.practiceleetcode;

import java.util.HashMap;

public class RomanToInteger {
      // I 1
      // V 5
      // X 10
      // L 50
      // C 100
      // D 500
      // M 1000
      public static int RomanIntegerConvert(String s) {
            HashMap<Character, Integer> hashmap = new HashMap<>();
            hashmap.put('I', 1);
            hashmap.put('V', 5);
            hashmap.put('X', 10);
            hashmap.put('L', 50);
            hashmap.put('C', 100);
            hashmap.put('D', 500);
            hashmap.put('M', 1000);
            int number = 0;
            for (int i = 0; i < s.length(); i++) {
                  if (i > 0 && hashmap.get(s.charAt(i)) > hashmap.get(s.charAt(i-1))) {
                        number += hashmap.get(s.charAt(i)) - 2 * hashmap.get(s.charAt(i - 1));
                  }
                  else {
                        number += hashmap.get(s.charAt(i));
                  }
                  
            }
            return number;
      }
}
