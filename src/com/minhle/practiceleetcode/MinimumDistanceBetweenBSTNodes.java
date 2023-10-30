package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MinimumDistanceBetweenBSTNodes {
    public int minDiffInBST(TreeNode root) {
        List<Integer> nums = new ArrayList<>();
        inorder(root, nums);
        Collections.sort(nums);
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < nums.size() - 1; i++) {
            res = Math.min(res, Math.abs(nums.get(i + 1) - nums.get(i)));
        }
        return res;


    }
    private void inorder(TreeNode root, List<Integer> nums) {
        if (root == null) {
            return;
        }
        inorder(root.left, nums);
        nums.add(root.val);
        inorder(root.right, nums);
    }
}
