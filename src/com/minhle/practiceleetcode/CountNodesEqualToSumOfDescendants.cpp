#include <unordered_map>

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
    int equalToDescendants(TreeNode* root) {
        res = 0;
        unordered_map<TreeNode*, long long> sum_of_all_subtrees;
        get_sum_of_all_subtrees(root, sum_of_all_subtrees);
        dfs(root, sum_of_all_subtrees);
        return res;
    }

    void dfs(TreeNode* root, unordered_map<TreeNode*, long long> &sum_of_all_subtrees)
    {
        if (root == nullptr)
        {
            return;
        }
        int sum_of_descendants = sum_of_all_subtrees[root] - root->val;
        if (root->val == sum_of_descendants)
        {
            ++res;
        }
        dfs(root->left, sum_of_all_subtrees);
        dfs(root->right, sum_of_all_subtrees);
    }

    long long get_sum_of_all_subtrees(TreeNode* root, unordered_map<TreeNode*, long long> &sum_of_all_subtrees)
    {
        if (root == nullptr)
        {
            return 0;
        }
        long long left_sum = get_sum_of_all_subtrees(root->left, sum_of_all_subtrees);
        long long right_sum = get_sum_of_all_subtrees(root->right, sum_of_all_subtrees);
        long long sum_of_this_subtree = root->val + left_sum + right_sum;
        sum_of_all_subtrees[root] = sum_of_this_subtree;
        return sum_of_this_subtree;
    }
private:
    int res;
};
