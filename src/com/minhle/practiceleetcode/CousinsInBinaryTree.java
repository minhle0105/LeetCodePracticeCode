package com.minhle.practiceleetcode;

public class CousinsInBinaryTree {
    public boolean isCousins(TreeNode root, int x, int y) {
        boolean sameP = sameParent(root, x, y);
        if (sameP) {
            return false;
        }
        int countX = countStep(root, x, 0);
        int countY = countStep(root, y, 0);
        return countX == countY;
    }

    private int countStep(TreeNode root, int val, int count) {
        if (root == null) return 0;
        if (root.val == val) {
            return count;
        }
        return Math.max(countStep(root.left, val, count + 1), countStep(root.right, val, count + 1));
    }

    private boolean sameParent(TreeNode root, int x, int y) {
        if (root == null) {
            return false;
        }
        if (root.left != null && root.right != null) {
            if ((root.left.val == x && root.right.val == y) || (root.right.val == x && root.left.val == y)) {
                return true;
            }
        }
        return sameParent(root.left, x, y) | sameParent(root.right, x, y);
    }
}
