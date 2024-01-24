package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

class PointP implements Comparable<PointP> {
    public int id;
    public double distance;

    public PointP(int id, double distance) {
        this.id = id;
        this.distance = distance;
    }

    @Override
    public int compareTo(PointP o) {
        return Double.compare(this.distance, o.distance);
    }
}

public class PathWithMaxProbability {
    static List<List<PointP>> graph;
    static double[] distance;
    static int[] path;

    private static void dijkstra(int startPoint) {
        PriorityQueue<PointP> heap = new PriorityQueue<>();
        heap.add(new PointP(startPoint, 1));
        distance[startPoint] = 1;
        while (!heap.isEmpty()) {
            PointP currentNode = heap.remove();
            int currentNodeId = currentNode.id;
            double currentDistance = currentNode.distance;
            if (distance[currentNodeId] != currentDistance) {
                continue;
            }
            for (int i = 0; i < graph.get(currentNodeId).size(); i++) {
                PointP nextNode = graph.get(currentNodeId).get(i);
                if (currentDistance * nextNode.distance > distance[nextNode.id]) {
                    distance[nextNode.id] = currentDistance * nextNode.distance;
                    heap.add(new PointP(nextNode.id, distance[nextNode.id]));
                    path[nextNode.id] = currentNodeId;
                }
            }
        }
    }

    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        Set<Integer> hasSeen = new HashSet<>();
        for (int i = 0; i < edges.length; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double cost = succProb[i];
            graph.get(a).add(new PointP(b, cost));
            graph.get(b).add(new PointP(a, cost));
            hasSeen.add(a);
            hasSeen.add(b);
        }
        distance = new double[n];
        path = new int[n];
        Arrays.fill(distance, Double.MIN_VALUE);
        Arrays.fill(path, -1);
        dijkstra(start);
        if (hasSeen.contains(end)) {
            return distance[end];
        }
        else {
            return 0.0000;
        }
    }

    @Test
    void failedTest() {
        int n = 3;
        int[][] edges = {{0,1},{1,2},{0,2}};
        double[] succProb = {0.5,0.5,0.2};
        int start = 0;
        int end = 2;
        double expected = 0.25000;
        double actual = maxProbability(n, edges, succProb, start, end);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest2() {
        int n = 3;
        int[][] edges = {{0,1}};
        double[] succProb = {0.5};
        int start = 0;
        int end = 2;
        double expected = 0.00000;
        double actual = maxProbability(n, edges, succProb, start, end);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest3() {
        int n = 3;
        int[][] edges = {{0,1},{1,2},{0,2}};
        double[] succProb = {0.5,0.5,0.3};
        int start = 0;
        int end = 2;
        double expected = 0.30000;
        double actual = maxProbability(n, edges, succProb, start, end);
        Assertions.assertEquals(expected, actual);
    }
}
