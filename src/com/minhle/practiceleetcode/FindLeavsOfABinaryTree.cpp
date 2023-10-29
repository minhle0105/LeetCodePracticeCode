#include <vector>
#include <queue>

using namespace std;

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
    vector<vector<int>> findLeaves(TreeNode* root)
    {
        vector<vector<int>> res;
        recursive(root, res);
        return res;
    }

    void recursive(TreeNode *root, vector<vector<int>> &res)
    {
        if (is_leaf(root))
        {
            res.push_back(vector<int>{root->val});
            return;
        }
        queue<TreeNode*> q;
        vector<int> leaves_here;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node->left != nullptr)
            {
                if (is_leaf(node->left))
                {
                    leaves_here.push_back(node->left->val);
                    node->left = nullptr;
                }
                else
                {
                    q.push(node->left);
                }
            }
            if (node->right != nullptr)
            {
                if (is_leaf(node->right))
                {
                    leaves_here.push_back(node->right->val);
                    node->right = nullptr;
                }
                else
                {
                    q.push(node->right);
                }
            }
        }
        res.push_back(leaves_here);
        recursive(root, res);
    }

    bool is_leaf(TreeNode* node)
    {
        return node->left == nullptr && node->right == nullptr;
    }
};