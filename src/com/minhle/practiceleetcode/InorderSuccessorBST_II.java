package com.minhle.practiceleetcode;

import java.util.*;

public class InorderSuccessorBST_II {
    static class Node {
        public int val;
        public Node left;
        public Node right;
        public Node parent;
    }
    Map<Integer, Node> map;
    public Node inorderSuccessor(Node node) {
        Node root = null;
        Node curr = node;
        while (curr.parent != null) {
            curr = curr.parent;
        }
        root = curr;
        return inorderSuccessorHelper(root, node);
    }

    public Node inorderSuccessorHelper(Node root, Node p) {
        map = new HashMap<>();
        addToMap(root);
        List<Integer> list = new ArrayList<>(map.keySet());
        Collections.sort(list);
        int nextVal = -1;
        for (Integer num : list) {
            if (num > p.val) {
                nextVal = num;
                break;
            }
        }
        if (nextVal == -1) {
            return null;
        }
        return map.get(nextVal);
    }
    private void addToMap(Node root) {
        if (root == null) {
            return;
        }
        map.put(root.val, root);
        addToMap(root.left);
        addToMap(root.right);
    }
}
