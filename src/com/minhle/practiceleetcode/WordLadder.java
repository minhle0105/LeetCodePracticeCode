package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class WordLadder {

    private static boolean isConnected(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        char[] s1Chars = s1.toCharArray();
        char[] s2Chars = s2.toCharArray();
        int count = 0;
        for (int i = 0; i < s1Chars.length; i++) {
            if (s1Chars[i] == s2Chars[i]) {
                count++;
            }
        }
        return count == s1.length() - 1;
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Map<String, List<String>> map = new HashMap<>();
        for (String word : wordList) {
            map.put(word, new ArrayList<>());
        }

        map.put(beginWord, new ArrayList<>());
        if (!map.containsKey(endWord)) {
            return 0;
        }
        for (String word : wordList) {
            if (isConnected(beginWord, word)) {
                map.get(beginWord).add(word);
                map.get(word).add(beginWord);
            }
        }

        for (int i = 0; i < wordList.size() - 1; i++) {
            String word1 = wordList.get(i);
            for (int j = i + 1; j < wordList.size(); j++) {
                String word2 = wordList.get(j);
                if (isConnected(word1, word2)) {
                    map.get(word1).add(word2);
                    map.get(word2).add(word1);
                }
            }
        }
        return bfs(map, beginWord, endWord);
    }

    private static int bfs(Map<String, List<String>> map, String beginWord, String endWord) {
        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        Map<String, Integer> levels = new HashMap<>();
        queue.add(beginWord);
        visited.add(beginWord);
        for (String word : map.keySet()) {
            levels.put(word, 0);
        }
        while (!queue.isEmpty()) {
            String thisWord = queue.remove();
            for (int i = 0; i < map.get(thisWord).size(); i++) {
                String nextWord = map.get(thisWord).get(i);
                if (!visited.contains(nextWord)) {
                    queue.add(nextWord);
                    visited.add(nextWord);
                    levels.put(nextWord, levels.get(thisWord) + 1);
                }
            }
        }
        if (levels.get(endWord) == 0) {
            return 0;
        }
        else {
            return levels.get(endWord) + 1;
        }
    }

    @Test
    void firstTest() {
        List<String> wordList = new ArrayList<>(Arrays.asList("hot","dot","dog","lot","log","cog"));
        String beginWord = "hit";
        String endWord = "cog";
        int expected = 5;
        int actual = ladderLength(beginWord, endWord, wordList);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        List<String> wordList = new ArrayList<>(Arrays.asList("hot","dot","dog","lot","log"));
        String beginWord = "hit";
        String endWord = "cog";
        int expected = 0;
        int actual = ladderLength(beginWord, endWord, wordList);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest() {
        List<String> wordList = new ArrayList<>(Arrays.asList("hot","dog"));
        String beginWord = "hot";
        String endWord = "dog";
        int expected = 0;
        int actual = ladderLength(beginWord, endWord, wordList);
        Assertions.assertEquals(expected, actual);
    }
}
