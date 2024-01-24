package com.minhle.practiceleetcode;

import java.util.*;

public class InsertDeleteGetRandomO1DuplicatesAllowed {
    static class RandomizedCollection {
        List<Integer> list;
        Map<Integer, Set<Integer>> map;
        Random rand;
        public RandomizedCollection() {
            list = new ArrayList<>();
            map = new HashMap<>();
            rand = new Random();
        }

        public boolean insert(int val) {
            boolean res = !map.containsKey(val);
            if (res) {
                map.put(val, new HashSet<>());
            }
            list.add(val);
            map.get(val).add(list.size() - 1);
            return res;
        }

        public boolean remove(int val) {
            boolean res = map.containsKey(val);
            // case 1: if the list does not contain value to delete
            if (!res) {
                return false;
            }

            // case 2: if the last value is the value to be deleted
            if (list.get(list.size() - 1) == val) {
                // get the last index (this one can be removed in O(1))
                int lastIndex = list.size() - 1;
                // this takes O(1)
                list.remove(lastIndex);
                map.get(val).remove(lastIndex);

                // if the value does not map to any index --> no existence --> remove
                if (map.get(val).size() == 0) {
                    map.remove(val);
                }
                return true;
            }
            // get an index of the value in the list
            int anIndexOfVal = -1;
            for (Integer key : map.get(val)) {
                anIndexOfVal = key;
                break;
            }
            // swap the value to the last element of the list, then remove the last element
            int lastIndex = list.size() - 1;
            int lastNumber = list.get(lastIndex);
            list.set(anIndexOfVal, lastNumber);
            list.remove(lastIndex);
            map.get(val).remove(anIndexOfVal);
            map.get(lastNumber).remove(lastIndex);
            map.get(lastNumber).add(anIndexOfVal);

            if (map.get(val).size() == 0) {
                map.remove(val);
            }
            if (map.get(lastNumber).size() == 0) {
                map.remove(lastNumber);
            }
            return true;
        }

        public int getRandom() {
            int max = list.size();
            int randomIndex = rand.nextInt(max);
            return list.get(randomIndex);
        }
    }
}
