package com.minhle.practiceleetcode;

import java.util.*;

public class InorderSuccessorBST {
    Map<Integer, TreeNode> map;
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
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
    private void addToMap(TreeNode root) {
        if (root == null) {
            return;
        }
        map.put(root.val, root);
        addToMap(root.left);
        addToMap(root.right);
    }
}
