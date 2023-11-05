#include <vector>

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        auto res = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); ++i)
        {
            insert(res, preorder[i]);
        }
        return res;
    }

    TreeNode* insert(TreeNode *root, int value)
    {
        if (root == nullptr)
        {
            return new TreeNode(value);;
        }
        if (root->val > value)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }
        return root;
    }
};