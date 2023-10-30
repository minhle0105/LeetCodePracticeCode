package com.minhle.practiceleetcode;

public class PathSum {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }
        else if (root.right == null & root.left == null & targetSum == root.val) {
            return true;
        }
        return hasPathSum(root.left, targetSum - root.val) | hasPathSum(root.right, targetSum - root.val);
    }
}
