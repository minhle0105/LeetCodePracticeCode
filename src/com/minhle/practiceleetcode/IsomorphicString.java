package com.minhle.practiceleetcode;

import java.util.*;

public class IsomorphicString {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> map = new HashMap<>();
        Map<Character, Character> reverseMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if (reverseMap.containsKey(t.charAt(i))) {
                if (reverseMap.get(t.charAt(i)) != s.charAt(i)) {
                    return false;
                }
            }
            else {
                reverseMap.put(t.charAt(i), s.charAt(i));
            }
            if (map.containsKey(s.charAt(i))) {
                if (t.charAt(i) != map.get(s.charAt(i))) {
                    return false;
                }
            }
            else {
                map.put(s.charAt(i), t.charAt(i));
            }
        }
        for (Character c : map.keySet()) {
            char value = map.get(c);
            if (reverseMap.get(value) != c) {
                return false;
            }
        }
        return true;
    }
}
