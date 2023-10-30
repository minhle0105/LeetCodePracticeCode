package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class ConvertBSTToDoublyLinkedList {
    static class Node {
        public int val;
        public Node left;
        public Node right;

        public Node() {}

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val,Node _left,Node _right) {
            val = _val;
            left = _left;
            right = _right;
        }
    };
    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return null;
        }
        List<Integer> list = new ArrayList<>();
        traverse(root, list);
        Node node = new Node(list.get(0));
        Node curr = node;
        attachToNode(node, curr, list, 1);
        return node;
    }

    private void traverse(Node root, List<Integer> list) {
        if (root == null) {
            return;
        }
        traverse(root.left, list);
        list.add(root.val);
        traverse(root.right, list);
    }

    private void attachToNode(Node node, Node curr, List<Integer> list, int pointer) {
        if (pointer == list.size()) {
            curr.right = node;
            node.left = curr;
            return;
        }
        curr.right = new Node(list.get(pointer));
        curr.right.left = curr;
        curr = curr.right;
        attachToNode(node, curr, list, pointer + 1);
    }
}
