package com.minhle.practiceleetcode;

public class MaximumBinaryTree {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return construct(nums, 0, nums.length);
    }
    private TreeNode construct(int[] nums, int l, int h) {
        int maxVal = Integer.MIN_VALUE;
        int pivot = -1;
        for (int i = l; i < h; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                pivot = i;
            }
        }
        if (pivot == -1) {
            return null;
        }
        TreeNode root = new TreeNode(maxVal);
        root.left = construct(nums, l, pivot);
        root.right = construct(nums, pivot + 1, h);
        return root;
    }
}
