package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class SubtreeOfAnotherTree {
    List<TreeNode> nodes;
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        nodes = new ArrayList<>();
        findSubRoot(root, subRoot.val);
        for (TreeNode node : nodes) {
            boolean res = checkEquals(node, subRoot);
            if (res) {
                return true;
            }
        }
        return false;
    }

    private boolean checkEquals(TreeNode root, TreeNode subRoot) {
        if (root == null & subRoot == null) {
            return true;
        }
        if (root == null | subRoot == null) {
            return false;
        }
        if (root.val != subRoot.val) {
            return false;
        }
        return checkEquals(root.left, subRoot.left) & checkEquals(root.right, subRoot.right);
    }

    private void findSubRoot(TreeNode root, int val) {
        if (root == null) {
            return;
        }
        if (root.val == val) {
            nodes.add(root);
        }
        findSubRoot(root.left, val);
        findSubRoot(root.right, val);
    }
}
