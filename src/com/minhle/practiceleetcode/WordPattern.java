package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.Map;

public class WordPattern {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) {
            return false;
        }
        Map<Character, String> map = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            if (map.containsKey(pattern.charAt(i))) {
                if (!words[i].equals(map.get(pattern.charAt(i)))) {
                    return false;
                }
            }
            else {
                map.put(pattern.charAt(i), words[i]);
            }
        }
        Map<String, Character> map2 = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            if (map2.containsKey(words[i])) {
                if (pattern.charAt(i) != map2.get(words[i])) {
                    return false;
                }
            }
            else {
                map2.put(words[i], pattern.charAt(i));
            }
        }
        return true;
    }
}
