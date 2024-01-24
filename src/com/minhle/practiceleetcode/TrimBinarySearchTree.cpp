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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root = trim(root, low, high);
        if (root == nullptr)
        {
            return root;
        }
        root->left = trim(root->left, low, high);
        root->right = trim(root->right, low, high);
        return root;
    }

    TreeNode* trim(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (low <= root->val && root->val <= high)
        {
            root->left = trim(root->left, low, high);
            root->right = trim(root->right, low, high);
        }
        else if (root->val < low)
        {
            return trim(root->right, low, high);
        }
        else if (root->val > high)
        {
            return trim(root->left, low, high);
        }
        return root;
    }
};
