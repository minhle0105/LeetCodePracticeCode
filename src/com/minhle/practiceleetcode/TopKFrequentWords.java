package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.*;

class Word implements Comparable<Word> {
    String value;
    int frequency;

    public Word(String value, int frequency) {
        this.value = value;
        this.frequency = frequency;
    }


    @Override
    public int compareTo(Word o) {
        if (o.frequency == this.frequency) {
            return o.value.compareTo(this.value);
        }
        return Integer.compare(this.frequency, o.frequency);
    }
}

public class TopKFrequentWords {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        PriorityQueue<Word> wordList = new PriorityQueue<>();
        for (String word : words) {
            if (map.containsKey(word)) {
                map.put(word, map.get(word) + 1);
            }
            else {
                map.put(word, 1);
            }
        }
        for (String word : map.keySet()) {
            Word w = new Word(word, map.get(word));
            wordList.add(w);
        }
        List<String> results = new ArrayList<>();
        int count = 0;
        while (count < k) {
            results.add(wordList.remove().value);
            count++;
        }
        return results;

    }

    @Test
    void firstTest() {
        String[] words = {"i","love","leetcode","i","love","coding"};
        int k = 2;
        topKFrequent(words, k);
    }
}
