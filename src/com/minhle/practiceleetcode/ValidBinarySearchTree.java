package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class ValidBinarySearchTree {
    public boolean isValidBST(TreeNode root) {
        return check(root);
    }

    private boolean check(TreeNode root) {
        if (root == null) {
            return true;
        }
        List<Integer> leftSub = new ArrayList<>();
        traverse(root.left, leftSub);
        List<Integer> rightSub = new ArrayList<>();
        traverse(root.right, rightSub);
        for (Integer left : leftSub) {
            if (left >= root.val) {
                return false;
            }
        }
        for (Integer right : rightSub) {
            if (right <= root.val) {
                return false;
            }
        }
        return check(root.left) & check(root.right);
    }

    private void traverse(TreeNode root, List<Integer> list) {
        if (root == null) return;
        list.add(root.val);
        traverse(root.left, list);
        traverse(root.right, list);
    }
}
