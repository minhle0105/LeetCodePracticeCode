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
    TreeNode* convertBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);
        vector<int> prefix_sum;
        prefix_sum.push_back(0);
        for (int value : values)
        {
            prefix_sum.push_back(prefix_sum.back() + value);
        }
        unordered_map<int, int> new_values;
        for (int i = 0; i < values.size(); ++i)
        {
            new_values[values[i]] = prefix_sum.back() - prefix_sum[i];
        }
        change_node_value(root, new_values);
        return root;
    }

    void change_node_value(TreeNode* root, unordered_map<int, int> &new_values)
    {
        if (root == nullptr)
        {
            return;
        }
        root->val = new_values[root->val];
        change_node_value(root->left, new_values);
        change_node_value(root->right, new_values);
    }

    void inorder(TreeNode* root, vector<int> &values)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
};
