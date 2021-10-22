package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class SymmetricTree {

    private boolean isSymmetricR(TreeNode left, TreeNode right) {
        if (left == null & right == null) {
            return true;
        }
        else if (left != null & right != null) {
            return left.val == right.val & isSymmetricR(left.left, right.right) & isSymmetricR(left.right, right.left);
        }
        return false;
    }

    public boolean isSymmetric(TreeNode root) {
        return isSymmetricR(root, root);
    }

    @Test
    void failTest() {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2, null, new TreeNode(3));
        root.right = new TreeNode(2, null, new TreeNode(3));
        Assertions.assertFalse(isSymmetric(root));
    }
}
