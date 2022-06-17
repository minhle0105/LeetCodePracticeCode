package com.minhle.practiceleetcode;

public class LowestCommonAncestorOfABinarySearchTree {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return search(root, p, q);
    }
    private TreeNode search(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }
        if (root.val < p.val & root.val < q.val) {
            return search(root.right, p, q);
        }
        else if (root.val > p.val & root.val > q.val) {
            return search(root.left, p, q);
        }
        return root;
    }
}
