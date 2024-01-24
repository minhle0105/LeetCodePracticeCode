import java.util.*;

public class TreeNode
{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<TreeNode> findDuplicateSubtrees(TreeNode root)
    {
        List<TreeNode> res = new ArrayList<>();
        Map<String, Integer> counter = new HashMap<>();
        dfs(root, res, counter);
        return res;
    }

    void dfs(TreeNode root, List<TreeNode> res, Map<String, Integer> counter)
    {
        if (root == null) {
            return;
        }
        String rootToString = serialize(root);
        counter.put(rootToString, counter.getOrDefault(rootToString, 0) + 1);
        if (counter.get(rootToString) == 2)
        {
            res.add(root);
        }
        dfs(root.left, res, counter);
        dfs(root.right, res, counter);
    }

    String serialize(TreeNode root)
    {
        StringBuilder res = new StringBuilder();
        serializeHelper(root, res);
        res.setLength(res.length() - 1);
        return res.toString();
    }

    void serializeHelper(TreeNode root, StringBuilder res)
    {
        if (root == null)
        {
            res.append("N,");
            return;
        }
        res.append(root.val).append(",");
        serializeHelper(root.left, res);
        serializeHelper(root.right, res);
    }
}
