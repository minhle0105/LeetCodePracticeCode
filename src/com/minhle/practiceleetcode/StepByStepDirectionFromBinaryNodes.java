package com.minhle.practiceleetcode;
import java.util.*;
import org.junit.jupiter.api.Test;

public class StepByStepDirectionFromBinaryNodes {
    public String getDirections(TreeNode root, int startValue, int destValue) {
        TreeNode startNode = findNode(root, startValue);
        TreeNode destNode = findNode(root, destValue);
        TreeNode lca = findLowestCommonLCA(root, startNode, destNode);
        String path1 = bfs(lca, startNode);
        String path2 = bfs(lca, destNode);
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < path1.length(); i++) {
            res.append("U");
        }
        for (int i = path2.length() - 1; i >= 0; i--) {
            res.append(path2.charAt(i));
        }
        return res.toString();
    }

    private String bfs(TreeNode root, TreeNode target) {
        Map<TreeNode, TreeNode> path = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        Set<TreeNode> visited = new HashSet<>();
        queue.add(root);
        visited.add(root);
        path.put(root, null);
        while (!queue.isEmpty()) {
            TreeNode thisNode = queue.remove();
            if (thisNode.left != null && thisNode.right != null) {
                TreeNode left = thisNode.left;
                TreeNode right = thisNode.right;
                if (!visited.contains(left)) {
                    visited.add(left);
                    queue.add(left);
                    path.put(left, thisNode);
                }
                if (!visited.contains(right)) {
                    visited.add(right);
                    queue.add(right);
                    path.put(right, thisNode);
                }
            }
            else if (thisNode.left != null) {
                TreeNode left = thisNode.left;
                if (!visited.contains(left)) {
                    visited.add(left);
                    queue.add(left);
                    path.put(left, thisNode);
                }
            }
            else if (thisNode.right != null) {
                TreeNode right = thisNode.right;
                if (!visited.contains(right)) {
                    visited.add(right);
                    queue.add(right);
                    path.put(right, thisNode);
                }
            }
        }
        StringBuilder res = new StringBuilder();
        TreeNode curr = target;
        while (path.get(curr) != null) {
            TreeNode parent = path.get(curr);
            if (curr == parent.left) {
                res.append("L");
            }
            else {
                res.append("R");
            }
            curr = path.get(curr);
        }
        return res.toString();

    }

    private TreeNode findNode(TreeNode root, int val) {
        if (root == null) {
            return null;
        }
        if (root.val == val) {
            return root;
        }
        TreeNode r = findNode(root.right, val);
        TreeNode l = findNode(root.left, val);
        if (r == null) {
            return l;
        }
        return r;
    }

    private TreeNode findLowestCommonLCA(TreeNode root, TreeNode p, TreeNode q) {
        return find(root, p, q);
    }

    private TreeNode find(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        if (root.val == p.val | root.val == q.val) return root;
        TreeNode left = find(root.left, p, q);
        TreeNode right = find(root.right, p, q);
        if (left == null) {
            return right;
        }
        if (right == null) {
            return left;
        }
        return root;
    }
}
