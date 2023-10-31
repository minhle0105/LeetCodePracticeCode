#include <utility>

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
    int averageOfSubtree(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

private:
    int res;

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        auto sum_n_nodes = get_sum_n_nodes(root);
        int avg = sum_n_nodes.first / sum_n_nodes.second;
        if (avg == root->val)
        {
            ++res;
        }
        dfs(root->left);
        dfs(root->right);
    }

    pair<int, int> get_sum_n_nodes(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {0, 0};
        }
        pair<int, int> here = {root->val, 1};
        pair<int, int> left = get_sum_n_nodes(root->left);
        pair<int, int> right = get_sum_n_nodes(root->right);
        return {here.first + left.first + right.first, here.second + left.second + right.second};
    }
};
