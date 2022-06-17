package com.minhle.practiceleetcode;

public class LowestCommonAncestorOfABinaryTree {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return findLCA(root, p, q);
    }

    private TreeNode findLCA(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }
        if (root.val == p.val | root.val == q.val) {
            return root;
        }
        TreeNode searchFromLeftSubtree = findLCA(root.left, p, q);
        TreeNode searchFromRightSubtree= findLCA(root.right, p, q);
        if (searchFromLeftSubtree == null) {
            return searchFromRightSubtree;
        }
        if (searchFromRightSubtree == null) {
            return searchFromLeftSubtree;
        }
        return root;
    }
}
