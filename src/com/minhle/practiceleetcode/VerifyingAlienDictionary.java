package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class VerifyingAlienDictionary {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> dictionary = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            dictionary.put(order.charAt(i), i);
        }
        String[] copy = new String[words.length];
        System.arraycopy(words, 0, copy, 0, words.length);
        Arrays.sort(copy, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                for (int i = 0; i < Math.min(o1.length(), o2.length()); i++) {
                    if (o1.charAt(i) != o2.charAt(i)) {
                        return Integer.compare(dictionary.get(o1.charAt(i)), dictionary.get(o2.charAt(i)));
                    }
                }
                if (o1.length() != o2.length()) {
                    return Integer.compare(o1.length(), o2.length());
                }
                return 0;
            }
        });
        for (int i = 0; i < copy.length; i++) {
            if (!copy[i].equals(words[i])) {
                return false;
            }
        }
        return true;
    }

    @Test
    void test1() {
        String[] words = {"hello","leetcode"};
        String order = "hlabcdefgijkmnopqrstuvwxyz";
        Assertions.assertTrue(isAlienSorted(words, order));
    }

    @Test
    void test2() {
        String[] words = {"word","world","row"};
        String order = "worldabcefghijkmnpqstuvxyz";
        Assertions.assertFalse(isAlienSorted(words, order));
    }

    @Test
    void test3() {
        String[] words = {"apple","app"};
        String order = "abcdefghijklmnopqrstuvwxyz";
        Assertions.assertFalse(isAlienSorted(words, order));
    }
}
