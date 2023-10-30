package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class NumberOfProvinces {
    public int findCircleNum(int[][] isConnected) {
        List<List<Integer>> graph = new ArrayList<>();
        int n = isConnected.length;
        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < isConnected.length; i++) {
            for (int j = 0; j < isConnected.length; j++) {
                if (isConnected[i][j] == 1) {
                    graph.get(i+1).add(j+1);
                    graph.get(j+1).add(i+1);
                }
            }
        }
        int[] visited = new int[n + 1];
        int count = 0;
        for (int i = 1; i < graph.size(); i++) {
            int result = bfs(graph, i, visited);
            if (result == 1) {
                count++;
            }
        }
        return count;
    }

    private int bfs(List<List<Integer>> graph, int startPoint, int[] visited) {
        if (visited[startPoint] == 1) return -1;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startPoint);
        visited[startPoint] = 1;
        while (!queue.isEmpty()) {
            int thisPoint = queue.remove();
            for (int i = 0; i < graph.get(thisPoint).size(); i++) {
                int nextPoint = graph.get(thisPoint).get(i);
                if (visited[nextPoint] == 0) {
                    visited[nextPoint] = 1;
                    queue.add(nextPoint);
                }
            }
        }
        return 1;
    }
}
