package com.minhle.practiceleetcode;

public class InsertIntoBST {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            root = new TreeNode(val);
        }
        else {
            insertR(root, val);
        }

        return root;
    }
    private void insertR(TreeNode root, int val) {
        if (root.val < val) {
            if (root.right == null) {
                root.right = new TreeNode(val);
                return;
            }
            insertR(root.right, val);
        }
        else {
            if (root.left == null) {
                root.left = new TreeNode(val);
                return;
            }
            insertR(root.left, val);
        }
    }
}
