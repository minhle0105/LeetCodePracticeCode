package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class BinaryTreePaths {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        Map<TreeNode, TreeNode> map = new HashMap<>();
        map.put(root, null);
        addToMap(root, map);
        List<TreeNode> leafs = new ArrayList<>();
        addLeafs(root, leafs);
        for (TreeNode leaf : leafs) {
            List<Integer> path = new ArrayList<>();
            while (map.get(leaf) != null) {
                path.add(leaf.val);
                leaf = map.get(leaf);
            }
            path.add(leaf.val);
            StringBuilder pathS = new StringBuilder();
            for (int i = path.size() - 1; i >= 0; i--) {
                pathS.append(path.get(i)).append("->");
            }
            pathS = new StringBuilder(pathS.substring(0, pathS.length() - 2));
            res.add(pathS.toString());
        }
        return res;
    }

    private void addLeafs(TreeNode root, List<TreeNode> leafs) {
        if (root == null) {
            return;
        }
        if (root.left == null & root.right == null) {
            leafs.add(root);
            return;
        }
        addLeafs(root.left, leafs);
        addLeafs(root.right, leafs);
    }

    private void addToMap(TreeNode root, Map<TreeNode, TreeNode> map) {
        if (root == null) {
            return;
        }
        if (root.left != null) {
            map.put(root.left, root);
            addToMap(root.left, map);
        }
        if (root.right != null) {
            map.put(root.right, root);
            addToMap(root.right, map);
        }
    }
}
