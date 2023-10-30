package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.LinkedHashMap;
import java.util.Map;

public class KthDistinctStringInArray {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> map = new LinkedHashMap<>();
        for (String s : arr) {
            if (map.containsKey(s)) {
                map.put(s, map.get(s) + 1);
            }
            else {
                map.put(s, 1);
            }
        }
        int count = 1;
        for (String key : map.keySet()) {
            if (map.get(key) == 1) {
                if (count == k) {
                    return key;
                }
                else {
                    count++;
                }
            }
        }
        return "";
    }

    @Test
    void firstTest() {
        String[] arr = {"d","b","c","b","c","a"};
        int k = 2;
        String expected = "a";
        String actual = kthDistinct(arr, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String[] arr = {"aaa","aa","a"};
        int k = 1;
        String expected = "aaa";
        String actual = kthDistinct(arr, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void blankTest() {
        String[] arr = {"a","b","a"};
        int k = 3;
        String expected = "";
        String actual = kthDistinct(arr, k);
        Assertions.assertEquals(expected, actual);
    }
}
