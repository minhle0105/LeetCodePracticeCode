package com.minhle.practiceleetcode;

public class InvertBinaryTree {
    public TreeNode invertTree(TreeNode root) {
        invert(root);
        return root;
    }
    private void invert(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            return;
        }
        if (root.left != null && root.right != null) {
            TreeNode temp = root.left;
            root.left = root.right;
            root.right = temp;
            invert(root.left);
            invert(root.right);
        }
        else if (root.left == null) {
            root.left = root.right;
            root.right = null;
            invert(root.left);
        }
        else {
            root.right = root.left;
            root.left = null;
            invert(root.right);
        }
    }
}
