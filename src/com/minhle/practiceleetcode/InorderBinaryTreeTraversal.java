package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class InorderBinaryTreeTraversal {
    public List<Integer> inorderTraversal(TreeNode root) {
        return traverse(root, new ArrayList<>());
    }

    private List<Integer> traverse(TreeNode root, List<Integer> list) {
        if (root != null) {
            list = traverse(root.left, list);
            list.add(root.val);
            list = traverse(root.right, list);
            return list;
        }
        return list;
    }

    @Test
    void firstTest() {
        TreeNode root = new TreeNode(1, null, new TreeNode(2, new TreeNode(3), null));
        List<Integer> expected = new ArrayList<>();
        expected.add(1);
        expected.add(3);
        expected.add(2);
        List<Integer> actual = inorderTraversal(root);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        TreeNode root = null;
        List<Integer> expected = new ArrayList<>();
        List<Integer> actual = inorderTraversal(root);
        Assertions.assertEquals(expected, actual);
    }
}
