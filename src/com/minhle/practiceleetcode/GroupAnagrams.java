package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.*;

public class GroupAnagrams {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0){
            return new ArrayList();
        }
        Map<String, List<String>> ans = new HashMap<String, List<String>>();
        for (String s : strs) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            String key = String.valueOf(ca);
            if (!ans.containsKey(key)) {
                ans.put(key, new ArrayList());
            }
            ans.get(key).add(s);
        }
        List<List<String>> results = new ArrayList<>(ans.values());
        return results;
    }

    @Test
    void firstTest() {
        String[] strs = {"eat","tea","tan","ate","nat","bat"};
        List<List<String>> results = groupAnagrams(strs);
        System.out.println("Done");
    }
}
