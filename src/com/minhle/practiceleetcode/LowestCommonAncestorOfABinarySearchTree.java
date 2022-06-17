package com.minhle.practiceleetcode;

public class LowestCommonAncestorOfABinarySearchTree {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode curr = root;
        while (curr != null) {
            if (p.val < curr.val & q.val < curr.val) {
                curr = curr.left;
            }
            else if (p.val > curr.val & q.val > curr.val) {
                curr = curr.right;
            }
            else {
                return curr;
            }
        }
        return null;
    }
}
