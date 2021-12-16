package com.minhle.practiceleetcode;

import java.util.*;

public class TopKFrequentElement {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> hashMap = new HashMap<>();
        for (int i : nums) {
            if (hashMap.containsKey(i)) {
                hashMap.put(i, hashMap.get(i) + 1);
            }
            else {
                hashMap.put(i, 1);
            }
        }
        PriorityQueue<Integer> heap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2.compareTo(o1);
            }
        });
        heap.addAll(hashMap.values());
        List<Integer> kFrequency = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            kFrequency.add(heap.remove());
        }
        Set<Integer> result = new HashSet<>();
        for (Integer i : kFrequency) {
            for (Integer j : hashMap.keySet()) {
                if (hashMap.get(j).equals(i)) {
                    result.add(j);
                }
            }
        }
        Object[] o = result.toArray();
        int[] finalResult = new int[o.length];
        for (int i = 0; i < o.length; i++) {
            finalResult[i] = (int) o[i];
        }
        return finalResult;
    }
}