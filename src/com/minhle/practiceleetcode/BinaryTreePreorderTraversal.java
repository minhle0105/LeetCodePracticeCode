package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class BinaryTreePreorderTraversal {
    // Preorder traversal means always go root -> left -> right
    // For example, we have the tree
    //                   1
    //                 /  \
    //                2    3
    //              /     /
    //             4     5
    //             \
    //              6
    // Then preorder traversal would mean 1 -> 2 -> 4 -> 6 -> 3 -> 5
    public List<Integer> preorderTraversalUsingTwoIterations(TreeNode root) {
        List<Integer> results = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                results.add(root.val);
                stack.push(root);
                root = root.left;
            }
            if (root == null) {
                root = stack.pop();
                root = root.right;
            }
        }
        return results;
    }

    public List<Integer> preorderTraversalUsingStack(TreeNode root) {
        List<Integer> results = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode currentNode = stack.pop();
            if (currentNode != null) {
                stack.push(currentNode.right);
                stack.push(currentNode.left);
                results.add(currentNode.val);
            }
        }
        return results;
    }

    public List<Integer> preorderTraversalRecursive(TreeNode root) {
        return traverse(root, new ArrayList<>());
    }
    private List<Integer> traverse(TreeNode root, List<Integer> list) {
        if (root != null) {
            list.add(root.val);
            list = traverse(root.left, list);
            list = traverse(root.right, list);
        }
        return list;
    }
}
