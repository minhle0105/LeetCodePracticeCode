package com.minhle.practiceleetcode;

import java.util.*;

public class GraphValidTree {
    public boolean validTree(int n, int[][] edges) {
        List<List<Integer>> graphs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graphs.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int a = edge[0];
            int b = edge[1];
            graphs.get(a).add(b);
            graphs.get(b).add(a);
        }
        boolean allConnected = isAllConnected(graphs);
        return allConnected;
    }

    private boolean isAllConnected(List<List<Integer>> graph) {
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        int start = -1;
        for (int i = 0; i < graph.size(); i++) {
            if (graph.get(i).size() != 0) {
                start = i;
                break;
            }
        }
        queue.add(start);
        visited.add(start);
        while (!queue.isEmpty()) {
            int thisPoint = queue.remove();
            List<Integer> neighbors = graph.get(thisPoint);
            for (Integer neighbor : neighbors) {
                if (!visited.contains(neighbor)) {
                    queue.add(neighbor);
                    visited.add(neighbor);
                }
            }
        }
        return visited.size() == graph.size();
    }



}
