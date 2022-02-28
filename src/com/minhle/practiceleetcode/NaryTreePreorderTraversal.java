package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

class NaryNode {
    public int val;
    public List<NaryNode> children;

    public NaryNode() {}

    public NaryNode(int _val) {
        val = _val;
    }

    public NaryNode(int _val, List<NaryNode> _children) {
        val = _val;
        children = _children;
    }
}

public class NaryTreePreorderTraversal {
    public List<Integer> preorder(NaryNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        List<Integer> vals = new ArrayList<>();
        dfs(root, vals);
        return vals;
    }

    private void dfs(NaryNode root, List<Integer> vals) {
        if (root == null) {
            return;
        }
        vals.add(root.val);
        for (NaryNode child : root.children) {
            dfs(child, vals);
        }
    }
}
