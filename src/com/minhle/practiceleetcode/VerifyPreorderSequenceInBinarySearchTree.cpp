#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        next = 0;
        auto root = build_tree(preorder, INT_MIN, INT_MAX);
        vector<int> root_preorder;
        preorder_traverse(root, root_preorder);
        return root_preorder == preorder;
    }

private:
    int next;

    void preorder_traverse(TreeNode* root, vector<int> &values)
    {
        if (root == nullptr)
        {
            return;
        }
        values.push_back(root->val);
        preorder_traverse(root->left, values);
        preorder_traverse(root->right, values);
    }

    TreeNode* build_tree(const vector<int> &values, int low, int high)
    {
        if (next == values.size())
        {
            return nullptr;
        }
        int val = values[next];
        if (val < low || val > high)
        {
            return nullptr;
        }
        auto res = new TreeNode(values[next]);
        ++next;
        res->left = build_tree(values, low, val - 1);
        res->right = build_tree(values, val + 1, high);
        return res;
    }
};
