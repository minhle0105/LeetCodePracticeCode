#include <unordered_map>
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
    double maximumAverageSubtree(TreeNode* root) {
        res = 0.0;
        subtree_info_cache.clear();

        get_sum_n_nodes(root);
        dfs(root);
        return res;
    }
private:
    double res;
    unordered_map<TreeNode*, pair<int, int>> subtree_info_cache;

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        auto sum_n_nodes = subtree_info_cache[root];
        double avg = static_cast<double>(sum_n_nodes.first) / sum_n_nodes.second;
        res = max(res, avg);
        dfs(root->left);
        dfs(root->right);
    }

    pair<int, int> get_sum_n_nodes(TreeNode* root)
    {
        if (subtree_info_cache.find(root) != subtree_info_cache.end())
        {
            return subtree_info_cache[root];
        }
        if (root == nullptr)
        {
            return {0, 0};
        }
        pair<int, int> here = {root->val, 1};
        pair<int, int> left = get_sum_n_nodes(root->left);
        pair<int, int> right = get_sum_n_nodes(root->right);
        subtree_info_cache[root] = {here.first + left.first + right.first, here.second + left.second + right.second};
        return subtree_info_cache[root];
    }
};
