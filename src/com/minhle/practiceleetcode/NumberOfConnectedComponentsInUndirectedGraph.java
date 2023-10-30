package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class NumberOfConnectedComponentsInUndirectedGraph {
    public int countComponents(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        int[] visited = new int[n];
        int count = 0;
        for (int i = 0; i < visited.length; i++) {
            if (bfs(i, graph, visited) == 1) {
                count++;
            }
        }
        return count;
    }

    private static int bfs(int startPoint, List<List<Integer>> graph, int[] visited) {
        if (visited[startPoint] == 1) {
            return -1;
        }
        visited[startPoint] = 1;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startPoint);
        while (!queue.isEmpty()) {
            int thisNumber = queue.remove();
            for (int i = 0; i < graph.get(thisNumber).size(); i++) {
                int nextNumber = graph.get(thisNumber).get(i);
                if (visited[nextNumber] == 0) {
                    queue.add(nextNumber);
                    visited[nextNumber] = 1;
                }
            }
        }
        return 1;
    }
}
