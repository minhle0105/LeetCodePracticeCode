package com.minhle.practiceleetcode;
import java.util.*;

public class MinimumGeneticMutation {
    public int minMutation(String start, String end, String[] bank) {
        if (bank.length == 0) {
            return -1;
        }
        Set<String> set = new HashSet<>();
        Collections.addAll(set, bank);
        if (!set.contains(end)) {
            return -1;
        }
        Map<String, List<String>> map = new HashMap<>();
        map.put(start, new ArrayList<>());
        map.put(end, new ArrayList<>());
        for (String word : bank) {
            map.put(word, new ArrayList<>());
        }
        for (String word : bank) {
            if (isConnected(start, word)) {
                map.get(start).add(word);
                map.get(word).add(start);
            }
            if (isConnected(end, word)) {
                map.get(end).add(word);
                map.get(word).add(end);
            }

        }
        for (int i = 0; i < bank.length - 1; i++) {
            for (int j = i + 1; j < bank.length; j++) {
                if (isConnected(bank[i], bank[j])) {
                    map.get(bank[i]).add(bank[j]);
                    map.get(bank[j]).add(bank[i]);
                }
            }
        }
        return bfs(map, start, end);
    }

    private int bfs(Map<String, List<String>> map, String start, String end) {
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        Map<String, String> path = new HashMap<>();
        queue.add(start);
        visited.add(start);
        path.put(start, "");
        while (!queue.isEmpty()) {
            String thisGene = queue.remove();
            if (!map.containsKey(thisGene)) {
                continue;
            }
            for (String next : map.get(thisGene)) {
                if (!visited.contains(next)) {
                    queue.add(next);
                    visited.add(next);
                    path.put(next, thisGene);
                }
            }
        }
        int res = 0;
        String curr = end;
        if (!visited.contains(end)) {
            return -1;
        }
        while (!path.get(curr).equals("")) {
            curr = path.get(curr);
            res++;
        }
        return res;
    }

    private boolean isConnected(String s1, String s2) {
        int countDiff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                countDiff++;
            }
        }
        return countDiff == 1;
    }
}
