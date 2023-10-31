import java.util.*;

public class TreeNode
{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        List<Integer> values = new ArrayList<>();
        inorder(root, values);
        values.remove(Integer.valueOf(key));
        return buildTree(values, 0, values.size() - 1);
    }

    private TreeNode buildTree(List<Integer> values, int left, int right) {
        if (left > right)
        {
            return null;
        }
        int mid = (left + right) / 2;
        TreeNode res = new TreeNode(values.get(mid));
        res.left = buildTree(values, left, mid - 1);
        res.right = buildTree(values, mid + 1, right);
        return res;
    }

    private void inorder(TreeNode root, List<Integer> values) {
        if (root == null)
        {
            return;
        }
        inorder(root.left, values);
        values.add(root.val);
        inorder(root.right, values);
    }
}