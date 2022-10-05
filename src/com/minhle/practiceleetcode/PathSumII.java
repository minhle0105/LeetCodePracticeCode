package com.minhle.practiceleetcode;
import java.util.*;

public class PathSumII {
    Map<TreeNode, TreeNode> map;
    List<TreeNode> leaves;
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return new ArrayList<>();
        }
        map = new HashMap<>();
        leaves = new ArrayList<>();
        bfs(root);
        List<List<Integer>> res = new ArrayList<>();
        for (TreeNode leave : leaves) {
            int sum = 0;
            TreeNode curr = leave;
            List<Integer> thisPath = new ArrayList<>();
            while (map.get(curr) != null) {
                sum += curr.val;
                thisPath.add(curr.val);
                curr = map.get(curr);

            }
            sum += curr.val;
            thisPath.add(curr.val);
            if (sum == targetSum) {
                Collections.reverse(thisPath);
                res.add(thisPath);
            }
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
