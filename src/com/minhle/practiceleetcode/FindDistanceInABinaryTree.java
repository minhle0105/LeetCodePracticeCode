package com.minhle.practiceleetcode;

public class FindDistanceInABinaryTree {
    public int findDistance(TreeNode root, int p, int q) {
        if (p == q) return 0;
        TreeNode startNode = findNode(root, p);
        TreeNode destNode = findNode(root, q);
        TreeNode lca = findLowestCommonLCA(root, startNode, destNode);
        int distance1 = bfs(lca, startNode);
        int distance2 = bfs(lca, destNode);
        return distance1 + distance2;
    }
    private int bfs(TreeNode root, TreeNode target) {
        Map<TreeNode, Integer> levels = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        Set<TreeNode> visited = new HashSet<>();
        queue.add(root);
        visited.add(root);
        levels.put(root, 0);
        while (!queue.isEmpty()) {
            TreeNode thisNode = queue.remove();
            if (thisNode.left != null && thisNode.right != null) {
                TreeNode left = thisNode.left;
                TreeNode right = thisNode.right;
                if (!visited.contains(left)) {
                    visited.add(left);
                    queue.add(left);
                    levels.put(left, levels.get(thisNode) + 1);
                }
                if (!visited.contains(right)) {
                    visited.add(right);
                    queue.add(right);
                    levels.put(right, levels.get(thisNode) + 1);
                }
            }
            else if (thisNode.left != null) {
                TreeNode left = thisNode.left;
                if (!visited.contains(left)) {
                    visited.add(left);
                    queue.add(left);
                    levels.put(left, levels.get(thisNode) + 1);
                }
            }
            else if (thisNode.right != null) {
                TreeNode right = thisNode.right;
                if (!visited.contains(right)) {
                    visited.add(right);
                    queue.add(right);
                    levels.put(right, levels.get(thisNode) + 1);
                }
            }
        }
        return levels.get(target);

    }
    private TreeNode findNode(TreeNode root, int val) {
        if (root == null) {
            return null;
        }
        if (root.val == val) {
            return root;
        }
        TreeNode r = findNode(root.right, val);
        TreeNode l = findNode(root.left, val);
        if (r == null) {
            return l;
        }
        return r;
    }
    private TreeNode findLowestCommonLCA(TreeNode root, TreeNode p, TreeNode q) {
        return find(root, p, q);
    }
    private TreeNode find(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        if (root.val == p.val | root.val == q.val) return root;
        TreeNode left = find(root.left, p, q);
        TreeNode right = find(root.right, p, q);
        if (left == null) {
            return right;
        }
        if (right == null) {
            return left;
        }
        return root;
    }
}
