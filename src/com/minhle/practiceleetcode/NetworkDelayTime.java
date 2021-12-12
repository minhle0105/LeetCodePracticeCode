package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

class Point {
    private final int id;
    private final Map<Integer, Integer> adjacencyWeight;

    public Point(int id) {
        this.id = id;
        this.adjacencyWeight = new HashMap<>();
    }

    public int getId() {
        return id;
    }

    public boolean hasNeighbors() {
        return this.adjacencyWeight.size() > 0;
    }

    public Map<Integer, Integer> getAdjacencyWeight() {
        return adjacencyWeight;
    }

    public void addNeighbor(int neighborId) {
        this.adjacencyWeight.put(neighborId, 0);
    }

    public void addNeighbor(int neighborId, int weight) {
        this.adjacencyWeight.put(neighborId, weight);
    }

    public int getWeighToANeighbor(int neighborId) {
        return this.adjacencyWeight.get(neighborId);
    }

    public Set<Integer> getAllNeighbors() {
        return this.adjacencyWeight.keySet();
    }

    public boolean containsNeighbor(int neighborId) {
        return this.adjacencyWeight.containsKey(neighborId);
    }
}


public class NetworkDelayTime {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<Point> graph = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            graph.add(new Point(i));
        }

        List<Integer> visited = new ArrayList<>();
        List<Integer> levels = new ArrayList<>();
        for (int i = 0; i < graph.size(); i++) {
            visited.add(0);
            levels.add(0);
        }

        for (int[] row : times) {
            graph.get(row[0]).addNeighbor(row[1], row[2]);
        }

        Stack<Point> stack = new Stack<>();
        stack.push(graph.get(k));
        visited.set(graph.get(k).getId(), 1);

        while (!stack.isEmpty()) {
            Point thisPoint = stack.pop();
            Set<Integer> neighborIds = thisPoint.getAllNeighbors();
            for (Integer neighbor : neighborIds) {
                Point nextPoint = graph.get(neighbor);
                if (visited.get(nextPoint.getId()) == 0) {
                    stack.push(graph.get(nextPoint.getId()));
                    visited.set(nextPoint.getId(), 1);
                    int distanceToAdd;
                    if (graph.get(k).containsNeighbor(nextPoint.getId())) {
                        int directDistance = graph.get(k).getWeighToANeighbor(nextPoint.getId());
                        int indirectDistance = levels.get(thisPoint.getId()) + thisPoint.getWeighToANeighbor(nextPoint.getId());
                        distanceToAdd = Math.min(directDistance, indirectDistance);
                    }
                    else {
                        distanceToAdd = levels.get(thisPoint.getId()) + thisPoint.getWeighToANeighbor(nextPoint.getId());
                    }
                    levels.set(nextPoint.getId(), distanceToAdd);
                }
            }
        }

        for (int i = 1; i < visited.size(); i++) {
            if (visited.get(i) == 0) {
                return -1;
            }
        }

        int maxVal = -1;
        for (Integer i : levels) {
            if (i > maxVal) {
                maxVal = i;
            }
        }
        return maxVal;
    }

    @Test
    void firstTest() {
        int[][] times = {{2,1,1},{2,3,1},{3,4,1}};
        int n = 4;
        int k = 2;
        int expected = 2;
        int actual = networkDelayTime(times, n, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int[][] times = {{1,2,1}};
        int n = 2;
        int k = 1;
        int expected = 1;
        int actual = networkDelayTime(times, n, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest() {
        int[][] times = {{1,2,1},{2,3,2},{1,3,4}};
        int n = 3;
        int k = 1;
        int expected = -1;
        int actual = networkDelayTime(times, n, k);
        Assertions.assertEquals(expected, actual);
    }
}
