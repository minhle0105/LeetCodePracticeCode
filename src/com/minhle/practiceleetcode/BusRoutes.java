package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class BusRoutes {

    private Map<Integer, List<Integer>> graphConversion (int[][] routes) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for(int i = 0; i < routes.length; i++) {
            for(int j = 0; j < routes[i].length; j++) {
                if (map.containsKey(routes[i][j]))
                    map.get(routes[i][j]).add(i);
                else {
                    map.put(routes[i][j], new ArrayList<Integer>());
                    map.get(routes[i][j]).add(i);
                }
            }
        }
        return map;

    }

//    public int numBusesToDestination(int[][] routes, int source, int target) {
//        List<List<Integer>> graph = graphConversion(routes);
//        Queue<Integer> queue = new LinkedList<>();
//        List<Integer> visited = new ArrayList<>();
//        List<Integer> path = new ArrayList<>();
//        for (int i = 0; i < graph.size(); i++) {
//            visited.add(0);
//            path.add(-1);
//        }
//        queue.add(source);
//        visited.set(source, 1);
//        while (!queue.isEmpty()) {
//            int thisStop = queue.remove();
//            for (int i = 0; i < graph.get(thisStop).size(); i++) {
//                int nextStop = graph.get(thisStop).get(i);
//                if (visited.get(nextStop) == 0) {
//                    queue.add(nextStop);
//                    visited.set(nextStop, 1);
//                    path.set(nextStop, thisStop);
//                }
//            }
//        }
//        int count = 0;
//        while (path.get(target) != -1) {
//            target = path.get(target);
//            count++;
//        }
//        return count == 0 ? -1 : count;
//    }

//    @Test
//    void firstTest() {
//        int[][] routes = {{1,2,7}, {3,6,7}};
//        int source = 1;
//        int target = 6;
//        int expected = 2;
//        int actual = numBusesToDestination(routes, source, target);
//        Assertions.assertEquals(expected, actual);
//    }
//
//    @Test
//    void secondTest() {
//        int[][] routes = {{7,12},{4,5,15},{6},{15,19},{9,12,13}};
//        int source = 15;
//        int target = 12;
//        int expected = -1;
//        int actual = numBusesToDestination(routes, source, target);
//        Assertions.assertEquals(expected, actual);
//    }
//
//    @Test
//    void failedTest () {
//        int[][] routes = {{24},{3,6,11,14,22},{1,23,24},{0,6,1},{1,3,8,11,20}};
//        int source = 20;
//        int target = 8;
//        int expected = 1;
//        int actual = numBusesToDestination(routes, source, target);
//        Assertions.assertEquals(expected, actual);
//    }

    @Test
    void testMap() {
        int[][] routes = {{1,2,7}, {3,6,7}};
        int source = 1;
        int target = 6;
        int expected = 2;
        graphConversion(routes);
//        Assertions.assertEquals(expected, actual);
    }
}
