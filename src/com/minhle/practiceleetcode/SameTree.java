package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SameTree {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null & q == null) {
            return true;
        }

        if (p == null | q == null) {
            return false;
        }


        if (p.val != q.val) {
            return false;
        }

        return isSameTree(p.left, q.left) & isSameTree(p.right, q.right);

    }

    @Test
    void firstTest() {
        TreeNode p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        TreeNode q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        Assertions.assertTrue(isSameTree(p, q));
    }

    @Test
    void secondTest () {
        TreeNode p = new TreeNode(1, new TreeNode(2), new TreeNode(1));
        TreeNode q = new TreeNode(1, new TreeNode(1), new TreeNode(2));
        Assertions.assertFalse(isSameTree(p, q));
    }

    @Test
    void lastTest () {
        TreeNode p = new TreeNode(1);
        p.left = new TreeNode(2);
        TreeNode q = new TreeNode(1, null, new TreeNode(2));
        Assertions.assertFalse(isSameTree(p, q));
    }
}
