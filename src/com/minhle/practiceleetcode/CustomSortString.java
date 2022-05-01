package com.minhle.practiceleetcode;

import java.util.*;

public class CustomSortString {
    public String customSortString(String order, String s) {
        List<Character> resultChars = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            resultChars.add(s.charAt(i));
        }
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            map.put(order.charAt(i), i);
        }
        Collections.sort(resultChars, new Comparator<Character>() {
            @Override
            public int compare(Character o1, Character o2) {
                if (map.containsKey(o1) && map.containsKey(o2)) {
                    return Integer.compare(map.get(o1), map.get(o2));
                }
                if (!map.containsKey(o1) && !map.containsKey(o2)) {
                    return 0;
                }
                if (map.containsKey(o1) && !map.containsKey(o2)) {
                    return 1;
                }
                return -1;
            }
        });
        StringBuilder result = new StringBuilder("");
        for (Character c : resultChars) {
            result.append(c);
        }
        return result.toString();
    }
}
