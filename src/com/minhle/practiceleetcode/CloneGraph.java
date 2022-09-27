package com.minhle.practiceleetcode;

import java.util.*;

public class CloneGraph {
    static class Node {
        public int val;
        public List<Node> neighbors;
        public Node() {
            val = 0;
            neighbors = new ArrayList<>();
        }
        public Node(int _val) {
            val = _val;
            neighbors = new ArrayList<>();
        }
        public Node(int _val, ArrayList<Node> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    }
    public Node cloneGraph(Node node) {
        List<List<Integer>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < node.neighbors.size(); i++) {
            adjacencyList.add(new ArrayList<>());
        }
        for (int i = 0; i < node.neighbors.size(); i++) {
            adjacencyList.get(i).add(node.neighbors.get(i).val);
        }
        return new Node(0);
    }
}
