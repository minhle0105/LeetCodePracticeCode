package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class FindTheLonelyNodes {
    public List<Integer> getLonelyNodes(TreeNode root) {
        List<Integer> results = new ArrayList<>();
        dfs(root, results);
        return results;
    }

    private void dfs(TreeNode root, List<Integer> results) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right != null) {
            results.add(root.right.val);
            dfs(root.right, results);
        }
        else if (root.right == null && root.left != null) {
            results.add(root.left.val);
            dfs(root.left, results);
        }
        else {
            dfs(root.left, results);
            dfs(root.right, results);
        }
    }
}
