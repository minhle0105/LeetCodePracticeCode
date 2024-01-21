#include "AllNecessaryHeaders.h"

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
    const int MIN_VALUE = -1000;
    int maxPathSum(TreeNode* root) {
        return traverse(root).second;
    }

    pair<int, int> traverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {MIN_VALUE, MIN_VALUE};
        }

        auto path_left = traverse(root->left);
        auto path_right = traverse(root->right);

        auto first = max(root->val, root->val + max(path_left.first, path_right.first));
        auto second = max(path_left.second, path_right.second); // ko di qua root
        second = max(second, root->val + path_left.first + path_right.first); // di qua root, qua trai, qua phai
        second = max(second, first); // either left + root or right + root

        return {first, second};
    }
};


