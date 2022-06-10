package com.minhle.practiceleetcode;

import java.util.HashSet;
import java.util.Set;

public class TwoSumBSTs {
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        Set<Integer> set = new HashSet<>();
        traverse(root2, set);
        return search(root1, set, target);
    }

    private boolean search(TreeNode root, Set<Integer> set, int target) {
        if (root == null) return false;
        int diff = target - root.val;
        if (set.contains(diff)) return true;
        return search(root.left, set, target) | search(root.right, set, target);
    }

    private void traverse(TreeNode root, Set<Integer> set) {
        if (root == null) return;
        set.add(root.val);
        traverse(root.right, set);
        traverse(root.left, set);
    }
}
