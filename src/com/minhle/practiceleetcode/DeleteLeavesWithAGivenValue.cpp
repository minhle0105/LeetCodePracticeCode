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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        while (true)
        {
            if (is_leaf(root) && root->val == target)
            {
                return nullptr;
            }
            int leaf_detected = 0;
            recursion(root, target, leaf_detected);
            if (leaf_detected == 0)
            {
                return root;
            }
        }
        return root;
    }
private:
    void recursion(TreeNode* root, int target, int &leaf_detected)
    {
        if (!root)
        {
            return;
        }
        if (root->left && is_leaf(root->left) && root->left->val == target)
        {
            root->left = nullptr;
            leaf_detected = 1;
        }
        if (root->right && is_leaf(root->right) && root->right->val == target)
        {
            root->right = nullptr;
            leaf_detected = 1;
        }
        recursion(root->left, target, leaf_detected);
        recursion(root->right, target, leaf_detected);
    }

    bool is_leaf(TreeNode *root)
    {
        return !root->left && !root->right;
    }
};
