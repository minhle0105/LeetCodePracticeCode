package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class HouseRobberIII {
    public int rob(TreeNode root) {
        int[] results = dfs(root);
        return Math.max(results[0], results[1]);
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[]{0, 0};
        }
        int[] left = dfs(root.left);
        int[] right = dfs(root.right);

        int caseWithRoot = root.val + left[1] + right[1];
        int caseWithoutRoot = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        return new int[]{caseWithRoot, caseWithoutRoot};
    }

}
