package com.minhle.practiceleetcode;
import org.junit.jupiter.api.Test;

import java.util.*;

public class DeepestLeavesSum {
    Map<TreeNode, Integer> leavesLevel;
    public int deepestLeavesSum(TreeNode root) {
        leavesLevel = new HashMap<>();
        int res = 0;
        bfs(root);
        int maxLevel = Integer.MIN_VALUE;
        for (TreeNode node : leavesLevel.keySet()) {
            maxLevel = Math.max(maxLevel, leavesLevel.get(node));
        }
        for (TreeNode node : leavesLevel.keySet()) {
            if (leavesLevel.get(node) == maxLevel) {
                res += node.val;
            }
        }
        return res;
    }
    private void bfs(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        Set<TreeNode> visited = new HashSet<>();
        Map<TreeNode, Integer> levels = new HashMap<>();
        levels.put(root, 1);
        queue.add(root);
        visited.add(root);
        while (!queue.isEmpty()) {
            TreeNode thisNode = queue.remove();
            if (thisNode.left == null && thisNode.right == null) {
                leavesLevel.put(thisNode, levels.get(thisNode));
            }
            if (thisNode.left != null) {
                if (!visited.contains(thisNode.left)) {
                    visited.add(thisNode.left);
                    queue.add(thisNode.left);
                    levels.put(thisNode.left, levels.get(thisNode) + 1);
                }
            }
            if (thisNode.right != null) {
                if (!visited.contains(thisNode.right)) {
                    visited.add(thisNode.right);
                    queue.add(thisNode.right);
                    levels.put(thisNode.right, levels.get(thisNode) + 1);
                }
            }
        }
    }
}
