package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class MinimumDepthOfBinaryTree {
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 1;
        }
        int rightMinDepth;
        int leftMinDepth;
        if (root.left != null) {
            leftMinDepth = minDepth(root.left);
        }
        else {
            leftMinDepth = Integer.MAX_VALUE;
        }
        if (root.right != null) {
            rightMinDepth = minDepth(root.right);
        }
        else {
            rightMinDepth = Integer.MAX_VALUE;
        }
        return 1 + Math.min(rightMinDepth, leftMinDepth);
    }

    @Test
    void firstTest() { // [3,9,20,null,null,15,7]
        TreeNode root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
        int expected = 2;
        int actual = minDepth(root);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() { // [2,null,3,null,4,null,5,null,6]
        TreeNode root = new TreeNode(2, null, new TreeNode(3, null, new TreeNode(4, null, new TreeNode(5, null, new TreeNode(6)))));
        int expected = 5;
        int actual = minDepth(root);
        Assertions.assertEquals(expected, actual);
    }
}
