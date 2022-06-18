package com.minhle.practiceleetcode;

import java.util.*;

public class InsertDeleteGetRandomO1 {
    static class RandomizedSet {
        Map<Integer, Integer> map;
        List<Integer> list;
        Random rand;

        public RandomizedSet() {
            map = new HashMap<>();
            list = new ArrayList<>();
            rand = new Random();
        }

        public boolean insert(int val) {
            if (map.containsKey(val)) return false;
            map.put(val, list.size());
            list.add(val);
            return true;
        }

        public boolean remove(int val) {
            if (!map.containsKey(val)) {
                return false;
            }
            int lastElement = list.get(list.size() - 1);
            int indexOfRemovedElement = map.get(val);
            list.set(indexOfRemovedElement, lastElement);
            map.put(lastElement, indexOfRemovedElement);
            list.remove(list.size() - 1);
            map.remove(val);
            return true;
        }

        public int getRandom() {
            return list.get(rand.nextInt(list.size()));
        }
    }
}
