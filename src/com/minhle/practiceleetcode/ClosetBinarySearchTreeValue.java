package com.minhle.practiceleetcode;

public class ClosetBinarySearchTreeValue {
    public int closestValue(TreeNode root, double target) {
        double currentMin = Double.MAX_VALUE;
        double[] data = {currentMin, 1.0};
        dfs(root, target, data);
        return (int) data[1];

    }

    private void dfs(TreeNode root, double target, double[] data) {
        if (root == null) {
            return;
        }
        double thisDistance = Math.abs(root.val - target);
        if (thisDistance < data[0]) {
            data[0] = thisDistance;
            data[1] = root.val;
        }
        dfs(root.left, target, data);
        dfs(root.right, target, data);

    }
}
