package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class RepeatedDNASequence {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length() - 9; i ++) {
            String DNA = s.substring(i, i + 10);
            if (map.containsKey(DNA)) {
                map.put(DNA, map.get(DNA) + 1);
            }
            else {
                map.put(DNA, 1);
            }
        }
        List<String> res = new ArrayList<>();
        for (String DNA : map.keySet()) {
            if (map.get(DNA) > 1) {
                res.add(DNA);
            }
        }
        return res;
    }
}
