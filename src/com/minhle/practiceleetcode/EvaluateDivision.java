package com.minhle.practiceleetcode;

import java.util.*;

public class EvaluateDivision {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, List<String[]>> graph = new HashMap<>();
        for (int i = 0; i < equations.size(); i++) {
            List<String> equation = equations.get(i);
            String node1 = equation.get(0);
            String node2 = equation.get(1);
            double cost1 = values[i];
            double cost2 = ((double) 1) / values[i];
            String[] pair1 = new String[]{node2 + "", cost1 + ""};
            String[] pair2 = new String[]{node1 + "", cost2 + ""};
            if (graph.containsKey(node1)) {
                graph.get(node1).add(pair1);
            } else {
                graph.put(node1, new ArrayList<>());
                graph.get(node1).add(pair1);
            }
            if (graph.containsKey(node2)) {
                graph.get(node2).add(pair2);
            } else {
                graph.put(node2, new ArrayList<>());
                graph.get(node2).add(pair2);
            }
        }
        double[] res = new double[queries.size()];
        for (int i = 0; i < res.length; i++) {
            String start = queries.get(i).get(0);
            String destination = queries.get(i).get(1);
            res[i] = bfs(graph, start, destination);
        }
        return res;
    }


    private double bfs(Map<String, List<String[]>> graph, String start, String destination) {
        if (!graph.containsKey(start)) {
            return -1.0;
        }
        if (!graph.containsKey(destination)) {
            return -1.0;
        }
        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        visited.add(start);
        queue.add(start);
        Map<String, Double> distances = new HashMap<>();
        distances.put(start, 1.0);
        while (!queue.isEmpty()) {
            String thisNode = queue.remove();
            List<String[]> neighbors = graph.get(thisNode);
            for (String[] neighbor : neighbors) {
                String neighborId = neighbor[0];
                double cost = Double.parseDouble(neighbor[1]);
                if (!distances.containsKey(neighborId)) {
                    distances.put(neighborId, 1.0);
                }
                if (!visited.contains(neighborId)) {
                    visited.add(neighborId);
                    queue.add(neighborId);
                    distances.put(neighborId, cost * distances.get(thisNode));
                }
                if (destination.equals(neighborId)) {
                    return distances.get(neighborId);
                }
            }
        }
        return distances.getOrDefault(destination, -1.0);
    }
}
