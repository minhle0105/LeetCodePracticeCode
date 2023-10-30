package com.minhle.practiceleetcode;

public class EvaluateBooleanBinaryTree {
    public boolean evaluateTree(TreeNode root) {
        return evals(root);
    }

    private boolean evals(TreeNode root) {
        if (root.val == 2) {
            return evals(root.left) | evals(root.right);
        }
        if (root.val == 3) {
            return evals(root.left) & evals(root.right);
        }
        return root.val != 0;
    }
}
