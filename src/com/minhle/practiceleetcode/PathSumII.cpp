#include <vector>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> current_path;
        dfs(root, targetSum, current_path, 0, res);
        return res;
    }

    void dfs(TreeNode *root, int targetSum, vector<int> &current_path, int current_sum, vector<vector<int>> &res)
    {
        if (root == nullptr)
        {
            return;
        }
        current_path.push_back(root->val);
        current_sum += root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (current_sum == targetSum)
            {
                res.push_back(current_path);
            }
            current_sum -= root->val;
            current_path.pop_back();
            return;
        }
        dfs(root->left, targetSum, current_path, current_sum, res);
        dfs(root->right, targetSum, current_path, current_sum, res);
        current_sum -= root->val;
        current_path.pop_back();
    }
};
