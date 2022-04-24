package com.minhle.practiceleetcode;

import java.util.*;

public class DesignUndergroundSystem {
    static class UndergroundSystem {
        Map<Integer, String[]> checkIns;
        Map<String, int[]> stations;

        public UndergroundSystem() {
            checkIns = new HashMap<>();
            stations = new HashMap<>();
        }

        public void checkIn(int id, String stationName, int t) {
            checkIns.put(id, new String[]{stationName, t + ""});
        }

        public void checkOut(int id, String stationName, int t) {
            String[] data = checkIns.get(id);
            String origin = data[0];
            int checkInTime = Integer.parseInt(data[1]);
            String concatName = origin + "-" + stationName;
            int tripTime = t - checkInTime;
            if (!stations.containsKey(concatName)) {
                stations.put(concatName, new int[2]);
            }
            stations.get(concatName)[0] += tripTime;
            stations.get(concatName)[1] += 1;
            checkIns.remove(id);
        }

        public double getAverageTime(String startStation, String endStation) {
            String concatName = startStation + "-" + endStation;
            int totalTripDuration = stations.get(concatName)[0];
            int totalTripCount = stations.get(concatName)[1];
            return ((double) totalTripDuration) / totalTripCount;
        }
    }
}
