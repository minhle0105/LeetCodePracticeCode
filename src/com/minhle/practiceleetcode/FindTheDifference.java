package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class FindTheDifference {
      public static char solution(String s, String t) {
            HashMap<Character, Integer> hashmap_1 = new HashMap<>();
            HashMap<Character, Integer> hashmap_2 = new HashMap<>();
            for (int i = 0; i < s.length(); i++) {
                  if (hashmap_1.containsKey(s.charAt(i))) {
                        hashmap_1.put(s.charAt(i), hashmap_1.get(s.charAt(i)) + 1);
                  } 
                  else {
                        hashmap_1.put(s.charAt(i), 1);
                  }
            }
            for (int i = 0; i < t.length(); i ++) {
                  if (hashmap_2.containsKey(t.charAt(i))) {
                        hashmap_2.put(t.charAt(i), hashmap_2.get(t.charAt(i)) + 1);
                  }
                  else {
                        hashmap_2.put(t.charAt(i), 1);
                  }
            }
            if (hashmap_1.size() != hashmap_2.size()) {
                  for (Character c : hashmap_2.keySet()) {
                        if (!hashmap_1.containsKey(c)) {
                              return c;
                        }
                  }
            }
            else {
                  for (Character c : hashmap_2.keySet()) {
                        if (hashmap_1.get(c) != hashmap_2.get(c)) {
                              return c;
                        }
                  }
            }
            return ' ';
            
      }
}
