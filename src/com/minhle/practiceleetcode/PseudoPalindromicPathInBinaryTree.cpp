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
    int res;
    int pseudoPalindromicPaths (TreeNode* root) {
        res = 0;
        unordered_map<int, int> counter;
        backtracking(root, counter);
        return res;
    }

    void backtracking(TreeNode* root, unordered_map<int, int> &counter)
    {
        if (counter.empty())
        {
            // at root
            ++counter[root->val];
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            int count_parity = 0;
            for (const auto &pair : counter)
            {
                if (pair.second % 2 != 0)
                {
                    ++count_parity;
                }
                if (count_parity == 2)
                {
                    break;
                }
            }
            if (count_parity <= 1)
            {
                ++res;
            }
            return;
        }
        if (root->left != nullptr)
        {
            ++counter[root->left->val];
            backtracking(root->left, counter);
            --counter[root->left->val];
        }
        if (root->right != nullptr)
        {
            ++counter[root->right->val];
            backtracking(root->right, counter);
            --counter[root->right->val];
        }
    }
};
