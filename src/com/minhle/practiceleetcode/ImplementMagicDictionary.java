package com.minhle.practiceleetcode;

import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

public class ImplementMagicDictionary {
    static class MagicDictionary {
        Set<String> set;

        public MagicDictionary() {
            set = new HashSet<>();
        }

        public void buildDict(String[] dictionary) {
            Collections.addAll(set, dictionary);
        }

        public boolean search(String searchWord) {
            for (String word : set) {
                if (compareString(word, searchWord)) {
                    return true;
                }
            }
            return false;
        }

        private boolean compareString(String s1, String s2) {
            if (s1.length() != s2.length()) {
                return false;
            }
            if (s1.equals(s2)) {
                return false;
            }
            int countDiff = 0;
            for (int i = 0; i < s1.length(); i++) {
                if (s1.charAt(i) != s2.charAt(i)) {
                    countDiff++;
                }
                if (countDiff > 1) {
                    return false;
                }
            }
            return true;
        }
    }
}
