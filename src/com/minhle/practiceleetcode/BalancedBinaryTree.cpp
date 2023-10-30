#include <cmath>
#include <cstdlib>

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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }
        int left_subtree_height = depth(root->left);
        int right_subtree_height = depth(root->right);
        if (abs(left_subtree_height - right_subtree_height) > 1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int depth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + max(depth(root->left), depth(root->right));
    }
};