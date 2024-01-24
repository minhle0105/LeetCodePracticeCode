package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

class MyCharacter implements Comparable<MyCharacter> {
    char val;
    int index;
    int frequency;

    public MyCharacter(char val, int index, int frequency) {
        this.val = val;
        this.index = index;
        this.frequency = frequency;
    }


    @Override
    public int compareTo(MyCharacter o) {
        if (this.frequency == o.frequency) {
            return Integer.compare(this.index, o.index);
        }
        return Integer.compare(this.frequency, o.frequency);
    }
}

public class FirstUniqueCharacterInString {

    public int firstUniqCharUsingSort(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            }
            else {
                map.put(c, 1);
            }
        }
        List<MyCharacter> characters = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            characters.add(new MyCharacter(s.charAt(i), i, map.get(s.charAt(i))));
        }
        Collections.sort(characters);
        if (characters.get(0).frequency == 1) {
            return characters.get(0).index;
        }
        return -1;
    }

    public int firstUniqChar(String s) {
        Map<Character, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if (hashMap.containsKey(s.charAt(i))) {
                hashMap.put(s.charAt(i), hashMap.get(s.charAt(i)) + 1);
            }
            else {
                hashMap.put(s.charAt(i), 1);
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (hashMap.get(s.charAt(i)) == 1) {
                return i;
            }
        }
        return -1;
    }

    @Test
    void firstTest() {
        int expected = 0;
        String s = "leetcode";
        int actual1 = firstUniqChar(s);
        int actual2 = firstUniqCharUsingSort(s);
        Assertions.assertTrue(expected == actual1 && expected == actual2);
    }

    @Test
    void secondTest() {
        int expected = 2;
        String s = "loveleetcode";
        int actual1 = firstUniqChar(s);
        int actual2 = firstUniqCharUsingSort(s);
        Assertions.assertTrue(expected == actual1 && expected == actual2);
    }

    @Test
    void lastTest() {
        int expected = -1;
        String s = "aabb";
        int actual1 = firstUniqChar(s);
        int actual2 = firstUniqCharUsingSort(s);
        Assertions.assertTrue(expected == actual1 && expected == actual2);
    }

    @Test
    void failTest() {
        int expected = 0;
        String s = "z";
        int actual1 = firstUniqChar(s);
        int actual2 = firstUniqCharUsingSort(s);
        Assertions.assertTrue(expected == actual1 && expected == actual2);
    }
}
