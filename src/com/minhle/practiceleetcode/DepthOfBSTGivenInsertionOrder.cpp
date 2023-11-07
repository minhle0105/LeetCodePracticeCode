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
    int maxDepthBST(vector<int>& order)
    {
        TreeNode* root = nullptr;
        for (int num : order)
        {
            insert(root, num);
        }
        return get_max_height(root);
    }

    TreeNode* insert(TreeNode* &root, int value)
    {
        if (root == nullptr)
        {
            root = new TreeNode(value);
            return root;
        }
        if (root->val < value)
        {
            insert(root->right, value);
        }
        else
        {
            insert(root->left, value);
        }
        return root;
    }

    int get_max_height(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return 1 + max(get_max_height(node->left), get_max_height(node->right));
    }
};
