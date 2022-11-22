package com.minhle.practiceleetcode;
import java.util.*;

public class AllNodesDistanceKInBinaryTree {
    Map<Integer, List<Integer>> graph;
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        graph = new HashMap<>();
        initGraph(root);
        connectNode(root);
        return bfs(target.val, k);
    }

    private void initGraph(TreeNode root) {
        if (root == null) {
            return;
        }
        if (!graph.containsKey(root.val)) {
            graph.put(root.val, new ArrayList<>());
        }
        initGraph(root.left);
        initGraph(root.right);
    }

    private void connectNode(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.left != null) {
            graph.get(root.val).add(root.left.val);
            graph.get(root.left.val).add(root.val);
        }
        if (root.right != null) {
            graph.get(root.val).add(root.right.val);
            graph.get(root.right.val).add(root.val);
        }
        connectNode(root.left);
        connectNode(root.right);
    }
    private List<Integer> bfs(int start, int k) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        Set<Integer> visited = new HashSet<>();
        visited.add(start);
        Map<Integer, Integer> levels = new HashMap<>();
        levels.put(start, 0);
        while (!queue.isEmpty()) {
            int thisNode = queue.remove();
            for (Integer neighbor : graph.get(thisNode)) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.add(neighbor);
                    levels.put(neighbor, levels.get(thisNode) + 1);
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        for (Integer key : levels.keySet()) {
            if (levels.get(key) == k) {
                res.add(key);
            }
        }
        return res;
    }
}
