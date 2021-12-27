package com.minhle.practiceleetcode;

import java.util.*;

class Node {
    int val;
    Node left;
    Node right;
    boolean isVisited;
    int distanceFromRoot;

    public Node(int val, Node left, Node right) {
        this.val = val;
        this.left = left;
        this.right = right;
        this.isVisited = false;
        this.distanceFromRoot = 0;
    }

    public Node(int val) {
        this.val = val;
        this.isVisited = false;
        this.distanceFromRoot = 0;
    }

    public void changeDistanceFromRoot(int distance) {
        this.distanceFromRoot += distance;
    }

    public void visitThisNode() {
        this.isVisited = true;
    }

    public void setLeft(Node left) {
        this.left = left;
    }

    public void setRight(Node right) {
        this.right = right;
    }
}

public class DFSWithTree {

    private static List<Node> inorder(Node root) {
        List<Node> result = new ArrayList<>();
        return inorder_R(root, result);
    }

    private static List<Node> inorder_R(Node root, List<Node> result) {
        if (root == null) {
            return result;
        }
        else {
            result.add(root);
            result = inorder_R(root.left, result);
            result = inorder_R(root.right, result);
        }
        return result;
    }

    private static Node initRoot() {
        Node root = new Node(5);
        Node left_1 = new Node(3);
        Node right_1 = new Node(8);
        Node left_2_1 = new Node(7);
        Node left_2_2 = new Node(9);
        Node left_2_3 = new Node(1);
        Node left_2_4 = new Node(2);
        Node left_3 = new Node(4);
        root.left = left_1;
        root.right = right_1;
        left_1.left = left_2_1;
        left_1.right = left_2_2;
        right_1.left = left_2_3;
        right_1.right = left_2_4;
        left_2_1.left = left_3;
        return root;
    }

    private static String dfs(Node root) {
        Stack<Node> stack = new Stack<>();
        StringBuilder dfsOrder = new StringBuilder();
        stack.push(root);
        root.visitThisNode();
        while (!stack.isEmpty()) {
            Node thisNode = stack.pop();
            dfsOrder.append(thisNode.val).append(" ");
            List<Node> children = new ArrayList<>();
            children.add(thisNode.right);
            children.add(thisNode.left);
            for (Node child : children) {
                if (child != null) {
                    if (!child.isVisited) {
                        stack.push(child);
                        child.visitThisNode();
                        child.changeDistanceFromRoot(thisNode.distanceFromRoot + 1);
                    }
                }
            }
        }

        return dfsOrder.toString();

    }

    private static String bfs(Node root) {
        Queue<Node> queue = new LinkedList<>();
        StringBuilder bfsOrder = new StringBuilder();
        queue.add(root);
        root.visitThisNode();
        while (!queue.isEmpty()) {
            Node thisNode = queue.remove();
            bfsOrder.append(thisNode.val).append(" ");
            List<Node> children = new ArrayList<>();
            children.add(thisNode.left);
            children.add(thisNode.right);
            for (Node child : children) {
                if (child != null) {
                    if (!child.isVisited) {
                        queue.add(child);
                        child.visitThisNode();
                        child.changeDistanceFromRoot(thisNode.distanceFromRoot + 1);
                    }
                }
            }
        }
        return bfsOrder.toString();

    }

    public static void main(String[] args) {
        Node root = initRoot();
        String dfsOrder = dfs(root);
        root = initRoot();
        String bfsOrder = bfs(root);
        System.out.println("DFS: " + dfsOrder);
        System.out.println("BFS: " + bfsOrder);
    }
}
