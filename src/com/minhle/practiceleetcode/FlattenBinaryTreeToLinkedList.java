package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;

public class FlattenBinaryTreeToLinkedList {
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        Queue<Integer> queue = new LinkedList<>();
        preorder(root, queue);
        root.left = null;
        root.right = null;
        TreeNode curr = root;
        queue.remove();
        flatten(curr, queue);
    }
    private void preorder(TreeNode root, Queue<Integer> queue) {
        if (root == null) {
            return;
        }
        queue.add(root.val);
        preorder(root.left, queue);
        preorder(root.right, queue);
    }
    private void flatten(TreeNode root, Queue<Integer> queue) {
        if (queue.isEmpty()) {
            return;
        }
        root.right = new TreeNode(queue.remove());
        root = root.right;
        flatten(root, queue);
    }
}
