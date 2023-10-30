package com.minhle.practiceleetcode;

import java.util.*;

class CharFreq implements Comparable<CharFreq> {
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

    @Override
    public int compareTo(CharFreq o) {
        return Integer.compare(o.frequency, this.frequency);
    }
}

public class SortCharacterByFrequency {

    private Map<Character, Integer> countChar(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            }
            else {
                map.put(c, 1);
            }
        }
        return map;
    }

    public String frequencySortUsingList(String s) {
        StringBuilder result = new StringBuilder();
        Map<Character, Integer> map = countChar(s);
        List<CharFreq> list = new ArrayList<>();
        for (char c : map.keySet()) {
            CharFreq charFreq = new CharFreq(c, map.get(c));
            list.add(charFreq);
        }

        Collections.sort(list);

        for (CharFreq charFreq : list) {
            for (int i = 0; i < charFreq.getFrequency(); i++) {
                result.append(charFreq.getValue());
            }
        }
        return result.toString();
    }


    public String frequencySortUsingHeap(String s) {
        StringBuilder result = new StringBuilder();
        Map<Character, Integer> map = countChar(s);
        for (char c : s.toCharArray()) {
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            }
            else {
                map.put(c, 1);
            }
        }

        PriorityQueue<CharFreq> list = new PriorityQueue<>();
        for (char c : map.keySet()) {
            CharFreq charFreq = new CharFreq(c, map.get(c));
            list.add(charFreq);
        }

        while (!list.isEmpty()) {
            CharFreq charFreq = list.remove();
            for (int i = 0; i < charFreq.getFrequency(); i++) {
                result.append(charFreq.getValue());
            }
        }
        return result.toString();
    }


}
