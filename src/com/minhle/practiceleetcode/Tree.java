package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Tree {
    public TreeNode_Codecademy root;

    public Tree(TreeNode_Codecademy root) {
        this.root = root;
    }

    public void print() {
        print(this.root, 0);
    }

    public void print(TreeNode_Codecademy current, int level) {
        String levelMarks = "";
        for (int i = 0; i < level; i++) {
            levelMarks += "-- ";
        }
        System.out.println(levelMarks + current.data);
        for (TreeNode_Codecademy child : current.children) {
            print(child, level + 1);
        }
    }

    public void depthFirstTraversal(TreeNode_Codecademy current) {
        System.out.print(current.data + " ");
        for (TreeNode_Codecademy child : current.children) {
            depthFirstTraversal(child);
        }
    }

    public void breadthFirstTraversal() {
        TreeNode_Codecademy current = this.root;
        Queue<TreeNode_Codecademy> queue = new LinkedList<>();
        queue.add(current);
        while (!queue.isEmpty()) {
            current = queue.poll();
            System.out.print(current.data + " ");
            queue.addAll(current.children);
        }
    }

    public static void main(String[] args) {
        TreeNode_Codecademy shirts = new TreeNode_Codecademy("Shirts");
        TreeNode_Codecademy blue = new TreeNode_Codecademy("Blue");
        TreeNode_Codecademy yellow = new TreeNode_Codecademy("Yellow");
        TreeNode_Codecademy red = new TreeNode_Codecademy("Red");
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
