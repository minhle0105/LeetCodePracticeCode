package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class RangeSumOfBST {
    public int rangeSumBST(TreeNode root, int low, int high) {
        int sum = 0;
        return dfs(root, low, high, sum);
    }


    private static int dfs(TreeNode root, int low, int high, int currentSum) {
        if (root == null) {
            return currentSum;
        }
        else {
            if (root.val <= high && root.val >= low) {
                currentSum += root.val;
            }
            if (root.val > low) {
                currentSum = dfs(root.left, low, high, currentSum);
            }
            if (root.val < high) {
                currentSum = dfs(root.right, low, high, currentSum);
            }
        }
        return currentSum;
    }

    @Test
    void firstTest() {
        TreeNode root = new TreeNode(10);
        TreeNode node1 = new TreeNode(5);
        TreeNode node2 = new TreeNode(15);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(7);
        TreeNode node5 = new TreeNode(18);
        root.left = node1;
        root.right = node2;
        node1.left = node3;
        node1.right = node4;
        node2.right = node5;
        int low = 7;
        int high = 15;
        int expected = 32;
        int actual = rangeSumBST(root, low, high);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        TreeNode root = new TreeNode(10);
        TreeNode node1 = new TreeNode(5);
        TreeNode node2 = new TreeNode(15);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(7);
        TreeNode node5 = new TreeNode(13);
        TreeNode node6 = new TreeNode(18);
        TreeNode node7 = new TreeNode(1);
        TreeNode node8 = new TreeNode(6);
        root.left = node1;
        root.right = node2;
        node1.left = node3;
        node1.right = node4;
        node2.right = node6;
        node2.left = node5;
        node3.left = node7;
        node4.left = node8;
        int low = 6;
        int high = 10;
        int expected = 23;
        int actual = rangeSumBST(root, low, high);
        Assertions.assertEquals(expected, actual);
    }

}
