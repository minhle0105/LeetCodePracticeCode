package com.minhle.practiceleetcode;
import java.util.*;

public class TimeBasedKeyValueStore {

    static class TimeMap {
        Map<String, Map<Integer, String>> map;

        public TimeMap() {
            map = new HashMap<>();
        }

        public void set(String key, String value, int timestamp) {
            if (!map.containsKey(key)) {
                map.put(key, new TreeMap<>(Collections.reverseOrder()));
            }
            map.get(key).put(timestamp, value);
        }

        public String get(String key, int timestamp) {
            if (!map.containsKey(key)) {
                return "";
            }
            if (map.get(key).containsKey(timestamp)) {
                return map.get(key).get(timestamp);
            }
            else {
                for (Integer time : map.get(key).keySet()) {
                    if (time <= timestamp) {
                        return map.get(key).get(time);
                    }
                }
            }
            return "";
        }
    }
}
