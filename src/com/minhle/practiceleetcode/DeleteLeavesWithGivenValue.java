package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.*;

public class DeleteLeavesWithGivenValue {
    Map<TreeNode, TreeNode> path;
    LinkedList<TreeNode> leaves;
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        while (true) {
            findLeaves(root);
            int res = removeLeaves(target);
            if (res == -1) break;
            if (res == 2) {
                root = null;
                break;
            }
        }
        return root;
    }

    private void findLeaves(TreeNode root) {
        path = new HashMap<>();
        leaves = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        Set<TreeNode> visited = new HashSet<>();
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
    }

    private int removeLeaves(int target) {
        boolean deleted = false;
        Set<TreeNode> removedLeaves = new HashSet<>();
        for (TreeNode leave : leaves) {
            if (leave.val == target) {
                deleted = true;
                TreeNode parent = path.get(leave);
                if (parent == null) {
                    removedLeaves.add(leave);
                    return 2;
                }
                if (leave == parent.left) {
                    parent.left = null;
                }
                else {
                    parent.right = null;
                }
                removedLeaves.add(leave);
            }
        }
        for (TreeNode removedLeave : removedLeaves) {
            leaves.remove(removedLeave);
        }
        return deleted ? 1 : -1;
    }
}
