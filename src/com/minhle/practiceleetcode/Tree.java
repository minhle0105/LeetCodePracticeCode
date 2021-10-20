package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Tree {
    public TreeNode root;

    public Tree(TreeNode root) {
        this.root = root;
    }

    public void print() {
        print(this.root, 0);
    }

    public void print(TreeNode current, int level) {
        String levelMarks = "";
        for (int i = 0; i < level; i++) {
            levelMarks += "-- ";
        }
        System.out.println(levelMarks + current.data);
        for (TreeNode child : current.children) {
            print(child, level + 1);
        }
    }

    public void depthFirstTraversal(TreeNode current) {
        System.out.print(current.data + " ");
        for (TreeNode child : current.children) {
            depthFirstTraversal(child);
        }
    }

    public void breadthFirstTraversal() {
        TreeNode current = this.root;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(current);
        while (!queue.isEmpty()) {
            current = queue.poll();
            System.out.print(current.data + " ");
            queue.addAll(current.children);
        }
    }

    public static void main(String[] args) {
        TreeNode shirts = new TreeNode("Shirts");
        TreeNode blue = new TreeNode("Blue");
        TreeNode yellow = new TreeNode("Yellow");
        TreeNode red = new TreeNode("Red");
        shirts.addChild(blue);
        shirts.addChild(yellow);
        shirts.addChild(red);
        blue.addChild("Small");
        blue.addChild("Large");
        yellow.addChild("Medium");
        yellow.addChild("X-Large");
        red.addChild("X-Small");
        red.addChild("Medium");

        Tree thisTree = new Tree(shirts);
        thisTree.print();
        shirts.removeChild("Medium");


    }
}
