package com.minhle.practiceleetcode;
import java.util.*;

public class UniqueWordAbbreviation {
    static class ValidWordAbbr {
        Map<String, Set<String>> map;
        public ValidWordAbbr(String[] dictionary) {
            map = new HashMap<>();
            for (String word : dictionary) {
                String abbreviation = abbr(word);
                if (map.containsKey(abbreviation)) {
                    map.get(abbreviation).add(word);
                } else {
                    map.put(abbreviation, new HashSet<>());
                    map.get(abbreviation).add(word);
                }
            }
        }

        private String abbr(String word) {
            if (word.length() <= 2) {
                return word;
            }
            String res = String.valueOf(word.charAt(0)) +
                    (word.length() - 2) +
                    word.charAt(word.length() - 1);
            return res;
        }

        public boolean isUnique(String word) {
            String abbreviation = abbr(word);
            if (!map.containsKey(abbreviation)) {
                return true;
            }
            if (map.get(abbreviation).size() > 1) {
                return false;
            }
            return map.get(abbreviation).contains(word);
        }
    }
}
