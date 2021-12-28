package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MinIndexSumOfTwoLists {

    private Map<String, Integer> mapStringToIndex(String[] list) {
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < list.length; i++) {
            map.put(list[i], i);
        }
        return map;
    }

    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> map1 = mapStringToIndex(list1);
        Map<String, Integer> map2 = mapStringToIndex(list2);
        int minSum = Integer.MAX_VALUE;
        List<String> results = new ArrayList<>();
        for (String s : map1.keySet()) {
            if (map2.containsKey(s)) {
                int thisSum = map1.get(s) + map2.get(s);
                if (thisSum < minSum) {
                    minSum = thisSum;
                }
            }
        }
        for (String s : map1.keySet()) {
            if (map2.containsKey(s)) {
                int thisSum = map1.get(s) + map2.get(s);
                if (thisSum == minSum) {
                    results.add(s);
                }
            }
        }
        String[] finalResults = new String[results.size()];
        for (int i = 0; i < finalResults.length; i++) {
            finalResults[i] = results.get(i);
        }
        return finalResults;
    }
}
