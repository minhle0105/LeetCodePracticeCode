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
    int sumEvenGrandparent(TreeNode* root) {
        sum = 0;
        dfs(root);
        return sum;
    }
private:
    int sum;

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val % 2 == 0)
        {
            if (root->left != nullptr)
            {
                sum += get_val(root->left->left);
                sum += get_val(root->left->right);
            }
            if (root->right != nullptr)
            {
                sum += get_val(root->right->left);
                sum += get_val(root->right->right);
            }
        }
        dfs(root->left);
        dfs(root->right);
    }

    int get_val(TreeNode *node)
    {
        return node == nullptr ? 0 : node->val;
    }
};
