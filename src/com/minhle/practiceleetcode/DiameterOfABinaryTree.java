package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class DiameterOfABinaryTree {

    private static int diameter;

    public int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        dfs(root);
        return diameter;
    }

    private static int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftPath = dfs(root.left);
        int rightPath = dfs(root.right);
        diameter = Math.max(diameter, leftPath + rightPath);
        return 1 + Math.max(leftPath, rightPath);
    }

    @Test
    void testDiameter1() {
        TreeNode root = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        root.right = node3;
        root.left = node2;
        node2.left = node4;
        node2.right = node5;
        int expected = 3;
        int actual = diameterOfBinaryTree(root);
        Assertions.assertEquals(expected, actual);
    }


}
