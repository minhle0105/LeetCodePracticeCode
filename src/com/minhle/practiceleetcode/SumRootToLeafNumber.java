package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.*;

public class SumRootToLeafNumber {
    Map<TreeNode, TreeNode> map;
    List<TreeNode> leaves;
    public int sumNumbers(TreeNode root) {
        map = new HashMap<>();
        leaves = new ArrayList<>();
        bfs(root);
        int res = 0;
        for (TreeNode leave : leaves) {
            StringBuilder path = new StringBuilder();
            TreeNode curr = leave;
            while (map.get(curr) != null) {
                path.append(curr.val);
                curr = map.get(curr);
            }
            path.append(curr.val);
            StringBuilder reversedPath = new StringBuilder();
            for (int i = path.length() - 1; i >= 0; i--) {
                reversedPath.append(path.charAt(i));
            }
            res += Integer.parseInt(reversedPath.toString());
        }
        return res;
    }
    private void bfs(TreeNode root) {
        Set<TreeNode> visited = new HashSet<>();
        Queue<TreeNode> queue = new LinkedList<>();
        map.put(root, null);
        visited.add(root);
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode thisNode = queue.remove();
            if (thisNode.left == null && thisNode.right == null) {
                leaves.add(thisNode);
            }
            if (thisNode.right != null && thisNode.left != null) {
                if (!visited.contains(thisNode.right)) {
                    visited.add(thisNode.right);
                    queue.add(thisNode.right);
                    map.put(thisNode.right, thisNode);
                }
                if (!visited.contains(thisNode.left)) {
                    visited.add(thisNode.left);
                    queue.add(thisNode.left);
                    map.put(thisNode.left, thisNode);
                }
            }
            else if (thisNode.left != null) {
                if (!visited.contains(thisNode.left)) {
                    visited.add(thisNode.left);
                    queue.add(thisNode.left);
                    map.put(thisNode.left, thisNode);
                }
            }
            else if (thisNode.right != null) {
                if (!visited.contains(thisNode.right)) {
                    visited.add(thisNode.right);
                    queue.add(thisNode.right);
                    map.put(thisNode.right, thisNode);
                }
            }
        }
    }
}
