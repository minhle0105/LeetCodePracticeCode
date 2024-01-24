package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.Map;

public class FindWordsThatCanBeFormedByCharacters {
    public int countCharacters(String[] words, String chars) {
        Map<Character, Integer> map = getFrequency(chars);
        int res = 0;
        for (String word : words) {
            boolean isTrue = true;
            Map<Character, Integer> mapThisWord = getFrequency(word);
            for (Character key : mapThisWord.keySet()) {
                if (!map.containsKey(key)) {
                    isTrue = false;
                    break;
                }
                if (map.get(key) < mapThisWord.get(key)) {
                    isTrue = false;
                    break;
                }
            }
            res += isTrue ? word.length() : 0;
        }
        return res;
    }

    private Map<Character, Integer> getFrequency(String word) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : word.toCharArray()) {
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            }
            else {
                map.put(c, 1);
            }
        }
        return map;
    }
}
