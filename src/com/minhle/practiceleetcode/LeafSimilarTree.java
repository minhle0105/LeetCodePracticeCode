package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class LeafSimilarTree {

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> tree1 = new ArrayList<>();
        List<Integer> tree2 = new ArrayList<>();
        dfs(root1, tree1);
        dfs(root2, tree2);
        if (tree1.size() != tree2.size()) {
            return false;
        }
        for (int i = 0; i < tree1.size(); i++) {
            if (tree1.get(i) != tree2.get(i)) {
                return false;
            }
        }
        return true;
    }

    private void dfs(TreeNode root, List<Integer> tree) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            tree.add(root.val);
        }
        dfs(root.left, tree);
        dfs(root.right, tree);
    }
}
