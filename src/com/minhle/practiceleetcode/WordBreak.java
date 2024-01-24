package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class WordBreak {

    public boolean wordBreak(String s, List<String> wordDict) {
        if (wordDict.size() == 1) {
            return s.equals(wordDict.get(0));
        }

        Set<String> dictionary = new HashSet<>(wordDict);

        List<String> splittedWords = new ArrayList<>();
        for (int i = 0; i < s.length();) {
            boolean found = false;
            for (int j = i; j < s.length(); j++) {
                String subString = s.substring(i, j + 1);
                if (dictionary.contains(subString)) {
                    splittedWords.add(subString);
                    i = j + 1;
                    found = true;
                    break;
                }
            }
            if (!found) {
                i++;
            }
        }
        int totalLength = 0;
        for (String word : splittedWords) {
            totalLength += word.length();
        }
        return totalLength == s.length();
    }
    @Test
    void test1() {
        String s = "leetcode";
        List<String> wordDict = Arrays.asList("leet", "code");
        Assertions.assertTrue(wordBreak(s, wordDict));
    }

    @Test
    void test2() {
        String s = "applepenapple";
        List<String> wordDict = Arrays.asList("apple","pen");
        Assertions.assertTrue(wordBreak(s, wordDict));
    }

    @Test
    void test3() {
        String s = "catsandog";
        List<String> wordDict = Arrays.asList("cats","dog","sand","and","cat");
        Assertions.assertFalse(wordBreak(s, wordDict));
    }

    @Test
    void failedTest() {
        String s = "aaaaaaa";
        List<String> wordDict = Arrays.asList("aaaa", "aaa");
        Assertions.assertTrue(wordBreak(s, wordDict));

    }
}
