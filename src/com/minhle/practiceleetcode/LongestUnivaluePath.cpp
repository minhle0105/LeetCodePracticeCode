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
    int res;
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        if (root == nullptr)
        {
            return 0;
        }
        dfs(root);

        return res;
    }

    int dfs(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftPath = 0;
        int rightPath = 0;

        if (node->left != nullptr && node->left->val == node->val)
        {
            leftPath = left + 1;
        }
        if (node->right != nullptr && node->right->val == node->val)
        {
            rightPath = right + 1;
        }

        res = max(res, leftPath + rightPath);

        return max(leftPath, rightPath);
    }
};
