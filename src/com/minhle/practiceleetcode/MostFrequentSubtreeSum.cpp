#include <vector>
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        reset_global_data_members();
        dfs(root);
        vector<int> res;
        for (const auto &pair : freq)
        {
            if (pair.second == max_freq)
            {
                res.push_back(pair.first);
            }
        }
        return res;
    }

private:
    int max_freq;
    unordered_map<int, int> freq;

    void reset_global_data_members()
    {
        max_freq = 0;
        freq.clear();
    }

    int dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int sum = root->val + dfs(root->left) + dfs(root->right);
        ++freq[sum];
        max_freq = max(max_freq, freq[sum]);
        return sum;
    }
};
