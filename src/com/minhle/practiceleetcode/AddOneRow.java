package com.minhle.practiceleetcode;

import java.util.*;

public class AddOneRow {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }
        Map<TreeNode, Integer> levels = getLevels(root);
        for (TreeNode node : levels.keySet()) {
            if (levels.get(node) == depth - 1) {
                if (node.left != null) {
                    TreeNode newNode = new TreeNode(val);
                    newNode.left = node.left;
                    node.left = newNode;
                }
                else {
                    node.left = new TreeNode(val);
                }
                if (node.right != null) {
                    TreeNode newNode = new TreeNode(val);
                    newNode.right = node.right;
                    node.right = newNode;
                }
                else {
                    node.right = new TreeNode(val);
                }
            }
        }
        return root;
    }

    private Map<TreeNode, Integer> getLevels(TreeNode root) {
        Map<TreeNode, Integer> map = new HashMap<>();
        Set<TreeNode> visited = new HashSet<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        map.put(root, 1);
        visited.add(root);
        while (!queue.isEmpty()) {
            TreeNode thisNode = queue.remove();
            if (thisNode.left != null) {
                if (!visited.contains(thisNode.left)) {
                    queue.add(thisNode.left);
                    visited.add(thisNode.left);
                    map.put(thisNode.left, map.get(thisNode) + 1);
                }
            }
            if (thisNode.right != null) {
                if (!visited.contains(thisNode.right)) {
                    queue.add(thisNode.right);
                    visited.add(thisNode.right);
                    map.put(thisNode.right, map.get(thisNode) + 1);
                }
            }
        }
        return map;
    }
}
