package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.*;

class CharFreq {
    private char value;
    private int frequency;

    public CharFreq(char value, int frequency) {
        this.value = value;
        this.frequency = frequency;
    }

    public char getValue() {
        return value;
    }

    public void setValue(char value) {
        this.value = value;
    }

    public int getFrequency() {
        return frequency;
    }

    public void setFrequency(int frequency) {
        this.frequency = frequency;
    }
}

public class SortCharacterByFrequency {
    public static String frequencySort(String s) {
        String result = "";
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            }
            else {
                map.put(c, 1);
            }
        }

        List<CharFreq> list = new ArrayList<>();
        for (char c : s.toCharArray()) {
            CharFreq charFreq = new CharFreq(c, map.get(c));
            list.add(charFreq);
        }

        PriorityQueue<CharFreq> heap = new PriorityQueue<>(new Comparator<CharFreq>() {
            @Override
            public int compare(CharFreq o1, CharFreq o2) {
                int o1Freq = o1.getFrequency();
                int o2Freq = o2.getFrequency();
                return Integer.compare(o2Freq, o1Freq);
            }
        });

        for (CharFreq charFreq : list) {
            heap.add(charFreq);
        }
        while (!heap.isEmpty()) {
            result += heap.remove().getValue();
        }
        char[] chars = result.toCharArray();
        Arrays.sort(chars);
        String finalResult = "";
        for (char c : chars) {
            finalResult += c;
        }
        return finalResult;
    }

    public static void main(String[] args) {
        String s = "tree";
        System.out.println(frequencySort(s));
    }
}
