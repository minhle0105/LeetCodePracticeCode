package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

class Point implements Comparable<Point> {
    public int id;
    public int distance;

    public Point(int id, int distance) {
        this.id = id;
        this.distance = distance;
    }

    @Override
    public int compareTo(Point o) {
        return Integer.compare(this.distance, o.distance);
    }
}


public class NetworkDelayTime {

    static List<List<Point>> graph;
    static int[] distance;
    static int[] path;
    static int[] visited;

    private static void prepareData(int[][] times, int n) {
        graph = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] data : times) {
            int a = data[0];
            int b = data[1];
            int c = data[2];
            graph.get(a).add(new Point(b, c));
        }
        distance = new int[graph.size()];
        path = new int[graph.size()];
        visited = new int[graph.size()];
        for (int i = 0; i < graph.size(); i++) {
            distance[i] = Integer.MAX_VALUE;
            path[i] = -1;
            visited[i] = 0;
        }
    }

    public int networkDelayTime(int[][] times, int n, int k) {
        PriorityQueue<Point> heap = new PriorityQueue<>();
        prepareData(times, n);
        heap.add(new Point(k, 0));
        distance[k] = 0;
        visited[k] = 1;
        while (!heap.isEmpty()) {
            Point currentPoint = heap.remove();
            int currentPointId = currentPoint.id;
            int currentDistance = currentPoint.distance;
            if (distance[currentPointId] != currentDistance) {
                continue;
            }
            for (int i = 0; i < graph.get(currentPointId).size(); i++) {
                Point nextPoint = graph.get(currentPointId).get(i);
                if (currentDistance + nextPoint.distance < distance[nextPoint.id]) {
                    distance[nextPoint.id] = currentDistance + nextPoint.distance;
                    heap.add(new Point(nextPoint.id, distance[nextPoint.id]));
                    path[nextPoint.id] = currentPointId;
                    visited[nextPoint.id] = 1;
                }
            }
        }
        int maxDistance = Integer.MIN_VALUE;
        for (int d : distance) {
            if (d > maxDistance && d != Integer.MAX_VALUE) {
                maxDistance = d;
            }
        }
        for (int i = 1; i < visited.length; i++) {
            if (visited[i] == 0) {
                return -1;
            }
        }
        if (maxDistance == 0) {
            return -1;
        }
        return maxDistance;
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
        int[][] times = {{1,2,1},{2,3,2},{1,3,1}};
        int n = 3;
        int k = 2;
        int expected = -1;
        int actual = networkDelayTime(times, n, k);
        Assertions.assertEquals(expected, actual);
    }
}
