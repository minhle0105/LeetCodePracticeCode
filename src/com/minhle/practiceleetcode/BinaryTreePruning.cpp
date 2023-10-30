struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root) ? root : nullptr;
    }

    bool dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return false;
        }
        bool res = root->val == 1;
        if (!dfs(root->left))
        {
            root->left = nullptr;
        }
        else
        {
            res = true;
        }
        if (!dfs(root->right))
        {
            root->right = nullptr;
        }
        else
        {
            res = true;
        }
        return res;
    }
};
