package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class PostorderBSTTraversal {
    public List<Integer> postorderTraversal(TreeNode root) {
        return traverse(root, new ArrayList<>());
    }

    private List<Integer> traverse(TreeNode root, List<Integer> list) {
        if (root != null) {
            list = traverse(root.left, list);
            list = traverse(root.right, list);
            list.add(root.val);
        }
        return list;
    }
}
