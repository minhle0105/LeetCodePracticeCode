/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
        {
            auto new_node = new TreeNode(val);
            new_node->left = root;
            return new_node;
        }
        dfs(root, val, depth, 1);
        return root;
    }

    void dfs(TreeNode* root, int val, int depth, int current_depth)
    {
        if (!root)
        {
            return;
        }
        if (current_depth == depth - 1)
        {
            auto new_left = new TreeNode(val);
            auto new_right = new TreeNode(val);

            auto curr_left = root->left;
            auto curr_right = root->right;

            root->left = new_left;
            root->right = new_right;

            new_left->left = curr_left;
            new_right->right = curr_right;
            return;
        }   
        dfs(root->left, val, depth, current_depth + 1);
        dfs(root->right, val, depth, current_depth + 1);
    }
};
