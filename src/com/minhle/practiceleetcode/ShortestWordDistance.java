package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class ShortestWordDistance {
    public int shortestDistance(String[] wordsDict, String word1, String word2) {
        Map<String, List<Integer>> map = new HashMap<>();
        Set<String> set = new HashSet<>(Arrays.asList(wordsDict));
        for (String word : set) {
            map.put(word, new ArrayList<>());
        }
        for (int i = 0; i < wordsDict.length; i++) {
            map.get(wordsDict[i]).add(i);
        }
        List<Integer> indexOfWord1 = map.get(word1);
        List<Integer> indexOfWord2 = map.get(word2);
        int shortestDistance = Integer.MAX_VALUE;
        for (Integer i : indexOfWord1) {
            for (Integer j : indexOfWord2) {
                if (Math.abs(i - j) < shortestDistance) {
                    shortestDistance = Math.abs(i - j);
                }
            }
        }
        return shortestDistance;
    }

    public int shortestDistanceDynamic(String[] wordsDict, String word1, String word2) {
        int indexWord1 = -1;
        int indexWord2 = -1;
        int shortestDistance = Integer.MAX_VALUE;
        for (int i = 0; i < wordsDict.length; i++) {
            if (wordsDict[i].equals(word1)) {
                indexWord1 = i;
            }
            if (wordsDict[i].equals(word2)) {
                indexWord2 = i;
            }
            if (indexWord1 != -1 && indexWord2 != -1) {
                shortestDistance = Math.min(shortestDistance, Math.abs(indexWord1 - indexWord2));
            }
        }
        return shortestDistance;
    }

    @Test
    void firstTest() {
        String[] wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
        String word1 = "coding";
        String word2 = "practice";
        int expected = 3;
        int actual = shortestDistance(wordsDict, word1, word2);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String[] wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
        String word1 = "makes";
        String word2 = "coding";
        int expected = 1;
        int actual = shortestDistance(wordsDict, word1, word2);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void firstTest1() {
        String[] wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
        String word1 = "coding";
        String word2 = "practice";
        int expected = 3;
        int actual = shortestDistanceDynamic(wordsDict, word1, word2);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest2() {
        String[] wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
        String word1 = "makes";
        String word2 = "coding";
        int expected = 1;
        int actual = shortestDistanceDynamic(wordsDict, word1, word2);
        Assertions.assertEquals(expected, actual);
    }
}
