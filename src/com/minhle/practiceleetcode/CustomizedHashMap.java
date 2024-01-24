package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class CustomizedHashMap {
    private Map<Integer, Integer> map;

    public CustomizedHashMap() {
        this.map = new HashMap<>();
    }

    public void put(int key, int value) {
        map.put(key, value);
    }

    public int get(int key) {
        if (map.containsKey(key)) {
            return map.get(key);
        }
        return -1;
    }

    public int size() {
        return this.map.size();
    }

    public void addToValue(int num) {
        map.replaceAll((k, v) -> map.get(k) + num);
    }

    public void addToKey(int num) {
        for (Integer i : map.keySet()) {
            int newKey = i + num;
            if (!map.containsKey(newKey)) {
                map.put(newKey, map.get(i));
                map.remove(i);
            }
            else {
                while (map.containsKey(newKey)) {
                    int currentVal = map.get(newKey);
                    map.put(newKey, map.get(i));
                    map.remove(i);

                }
            }

        }
    }

    public void printMap() {
        for (Integer i : map.keySet()) {
            System.out.println(i + " -> " + map.get(i));
        }
    }

    public static void main(String[] args) {
        CustomizedHashMap map = new CustomizedHashMap();
        map.put(1,2);
        map.put(2,3);
        map.put(3,4);
        System.out.println("Before: ");
        map.printMap();
        System.out.println("After adding 1 to key: ");
        map.addToKey(1);
        map.printMap();

    }


}
