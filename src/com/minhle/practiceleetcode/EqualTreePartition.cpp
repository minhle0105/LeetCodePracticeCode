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
    bool checkEqualTree(TreeNode* root) {
        int total_sum = get_total_sum(root);
        if (total_sum % 2 != 0)
        {
            return false;
        }
        int half_sum = total_sum / 2;
        return check(root->left, half_sum) || check(root->right, half_sum);
    }

    bool check(TreeNode *root, int half_sum)
    {
        if (root == nullptr)
        {
            return false;
        }
        int total_sum = get_total_sum(root);
        if (total_sum == half_sum)
        {
            return true;
        }
        return check(root->left, half_sum) || check(root->right, half_sum);
    }

    int get_total_sum(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return root->val + get_total_sum(root->left) + get_total_sum(root->right);
    }
};