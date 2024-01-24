package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class UniqueMorseCodeWords {
    public int uniqueMorseRepresentations(String[] words) {
        String[] codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        Map<Character, String> map = new HashMap<>();
        int index = 0;
        for (int i = 97; i < 97 + 26; i++) {
            map.put((char) i, codes[index]);
            index++;
        }
        Set<String> set = new HashSet<>();
        for (String word : words) {
            StringBuilder morse = new StringBuilder();
            for (char c : word.toCharArray()) {
                morse.append(map.get(c));
            }
            set.add(morse.toString());
        }
        return set.size();
    }
}