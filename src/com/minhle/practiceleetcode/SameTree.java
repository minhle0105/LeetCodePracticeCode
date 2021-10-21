package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SameTree {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        try {
            if (p.val != q.val) {
                return false;
            }
        }
        catch (NullPointerException e) {
            if (p == null & q != null) {
                return false;
            }
            if (p != null & q == null) {
                return false;
            }
            if (p == null & q == null) {
                return true;
            }
        }

        TreeNode leftSub1 = p.left;
        TreeNode leftSub2 = q.left;
        TreeNode rightSub1 = p.right;
        TreeNode rightSub2 = q.right;

        boolean firstFalseCondition = (leftSub1 == null & leftSub2 != null);
        boolean secondFalseCondition = (leftSub1 != null & leftSub2 == null);
        boolean thirdFalseCondition = (rightSub1 == null & rightSub2 != null);
        boolean forthFalseCondition = (rightSub1 != null & rightSub1 == null);
        if (firstFalseCondition | secondFalseCondition | thirdFalseCondition | forthFalseCondition) {
            return false;
        }
        else {
            leftSub1 = p.left;
            leftSub2 = q.left;
            rightSub1 = p.right;
            rightSub2 = q.right;
            return isSameTree(leftSub1, leftSub2) & isSameTree(rightSub1, rightSub2);
        }

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
