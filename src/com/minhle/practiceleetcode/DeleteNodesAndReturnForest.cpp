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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& td) {
        unordered_set<int> del(td.begin(), td.end());
        vector<TreeNode*> res;
        root = recursion(root, del, res);
        if (root)
        {
            res.push_back(root);
        }
        return res;
    }

    TreeNode* recursion(TreeNode *curr, unordered_set<int> &del, vector<TreeNode*> &res)
    {
        if (!curr)
        {
            return nullptr;
        }
        curr->left = recursion(curr->left, del, res);
        curr->right = recursion(curr->right, del, res);

        if (del.find(curr->val) != del.end())
        {
            if (curr->left)
            {
                res.push_back(curr->left);
            }
            if (curr->right)
            {
                res.push_back(curr->right);
            }
            return nullptr;
        }
        return curr;
    }
};
