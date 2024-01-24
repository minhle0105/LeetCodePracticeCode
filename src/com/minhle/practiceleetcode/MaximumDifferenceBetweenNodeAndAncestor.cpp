#include <algorithm>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        traverse_tree(root, root->val);
        if (root->left != nullptr)
        {
            dfs(root->left);
        }
        if (root->right != nullptr)
        {
            dfs(root->right);
        }
    }

    void traverse_tree(TreeNode* root, int root_val)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left != nullptr)
        {
            res = max(res, abs(root_val - root->left->val));
            traverse_tree(root->left, root_val);
        }
        if (root->right != nullptr)
        {
            res = max(res, abs(root_val - root->right->val));
            traverse_tree(root->right, root_val);
        }
    }
private:
    int res;
};
