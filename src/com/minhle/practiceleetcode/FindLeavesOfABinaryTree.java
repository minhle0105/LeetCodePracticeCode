package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.*;

public class FindLeavesOfABinaryTree {
    List<List<Integer>> res;
    public List<List<Integer>> findLeaves(TreeNode root) {
        res = new ArrayList<>();
        while (true) {
            int res = bfs(root);
            if (res == -1) {
                break;
            }
        }
        return res;
    }
    private int bfs(TreeNode root) {
        List<Integer> thisLevelLeaves = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        Set<TreeNode> visited = new HashSet<>();
        Map<TreeNode, TreeNode> path = new HashMap<>();
        Set<TreeNode> leaves = new HashSet<>();

        queue.add(root);
        visited.add(root);
        path.put(root, null);
        while (!queue.isEmpty()) {
            TreeNode thisNode = queue.remove();
            if (thisNode.left == null && thisNode.right == null) {
                leaves.add(thisNode);
            }
            else if (thisNode.left == null) {
                if (!visited.contains(thisNode.right)) {
                    visited.add(thisNode.right);
                    queue.add(thisNode.right);
                    path.put(thisNode.right, thisNode);
                }
            }
            else if (thisNode.right == null) {
                if (!visited.contains(thisNode.left)) {
                    visited.add(thisNode.left);
                    queue.add(thisNode.left);
                    path.put(thisNode.left, thisNode);
                }
            }
            else {
                if (!visited.contains(thisNode.left)) {
                    visited.add(thisNode.left);
                    queue.add(thisNode.left);
                    path.put(thisNode.left, thisNode);
                }
                if (!visited.contains(thisNode.right)) {
                    visited.add(thisNode.right);
                    queue.add(thisNode.right);
                    path.put(thisNode.right, thisNode);
                }
            }
        }
        boolean setRootNull = false;
        for (TreeNode leave : leaves) {
            thisLevelLeaves.add(leave.val);
            TreeNode parent = path.get(leave);
            if (parent == null) {
                setRootNull = true;
                continue;
            }
            if (parent.left == leave) {
                parent.left = null;
            }
            else {
                parent.right = null;
            }
        }
        res.add(thisLevelLeaves);
        return setRootNull ? -1 : 1;
    }
}
