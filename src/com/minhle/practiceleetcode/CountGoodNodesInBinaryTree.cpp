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
    int goodNodes(TreeNode* root) {
        vector<int> nodes;
        int one_smaller_than_min = ((-1) * pow(10, 4)) - 1;
        dfs(root, one_smaller_than_min, nodes);
        return nodes.size();
    }

    void dfs(TreeNode* root, int max_val, vector<int> &nodes)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val >= max_val)
        {
            max_val = root->val;
            nodes.push_back(root->val);
        }
        dfs(root->left, max_val, nodes);
        dfs(root->right, max_val, nodes);
    }
};
