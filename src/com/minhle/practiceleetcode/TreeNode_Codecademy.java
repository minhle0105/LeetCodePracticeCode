package com.minhle.practiceleetcode;

import java.util.ArrayList;

public class TreeNode_Codecademy {

    public Object data;
    public ArrayList<TreeNode_Codecademy> children;

    public TreeNode_Codecademy(Object data) {
        this.data = data;
        this.children = new ArrayList<TreeNode_Codecademy>();
    }

    public void addChild(TreeNode_Codecademy child) {
        this.children.add(child);
    }

    public void addChild(Object childData) {
        TreeNode_Codecademy child = new TreeNode_Codecademy(childData);
        this.children.add(child);
    }

    public void removeChild(TreeNode_Codecademy childToRemove) {
        if (this.children.isEmpty()) {
            return;
        } else if (this.children.contains(childToRemove)) {
            this.children.remove(childToRemove);
            return;
        } else {
            for (TreeNode_Codecademy child : this.children) {
                child.removeChild(childToRemove);
            }
        }
    }

    public void removeChild(Object data) {
        if (this.children.isEmpty()) {
            return;
        }
        for (TreeNode_Codecademy child : this.children) {
            if (child.data == data) {
                removeChild(child);
                return;
            }
        }
        for (TreeNode_Codecademy child : this.children) {
            child.removeChild(data);
        }
    }
}
