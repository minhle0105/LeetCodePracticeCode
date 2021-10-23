package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class MaximumDepthOfBinaryTree {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }

    @Test
    void firstTest() {
        TreeNode root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
        int expected = 3;
        int actual = maxDepth(root);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        TreeNode root = new TreeNode(1, null, new TreeNode(2));
        int expected = 2;
        int actual = maxDepth(root);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void thirdTest() {
        TreeNode root = null;
        int expected = 0;
        int actual = maxDepth(root);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void lastTest() {
        TreeNode root = new TreeNode(1);
        int expected = 1;
        int actual = maxDepth(root);
        Assertions.assertEquals(expected, actual);
    }
}
