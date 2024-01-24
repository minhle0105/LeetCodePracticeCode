#include <unordered_map>

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
    int res;
    // same idea as prefix sum
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return root->val == targetSum ? 1 : 0;
        }
        res = 0;
        unordered_map<long, int> sum_freq;
        sum_freq[0] = 1;
        dfs(root, targetSum, 0, sum_freq);
        return res;
    }

    void dfs(TreeNode* root, int targetSum, long currentSum, unordered_map<long, int> &sum_freq)
    {
        if (root == nullptr)
        {
            return;
        }
        currentSum += root->val;
        if (sum_freq.find(currentSum - targetSum) != sum_freq.end())
        {
            res += sum_freq[currentSum - targetSum];
        }
        ++sum_freq[currentSum];
        dfs(root->left, targetSum, currentSum, sum_freq);
        dfs(root->right, targetSum, currentSum, sum_freq);
        --sum_freq[currentSum];
        currentSum -= root->val;
    }
};
