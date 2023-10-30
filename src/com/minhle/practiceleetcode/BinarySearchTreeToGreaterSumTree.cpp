#include <vector>
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
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> all_values;
        inorder(root, all_values);
        vector<int> prefix_sum;
        prefix_sum.push_back(all_values.front());
        for (int i = 1; i < all_values.size(); ++i)
        {
            prefix_sum.push_back(all_values.at(i) + prefix_sum.back());
        }
        unordered_map<int, int> old_to_new;
        for (int i = 0; i < all_values.size(); ++i)
        {
            old_to_new[all_values[i]] = all_values[i] + (prefix_sum.back() - prefix_sum.at(i));
        }
        change(root, old_to_new);
        return root;
    }

    void change(TreeNode *root, unordered_map<int, int> &values)
    {
        if (root == nullptr)
        {
            return;
        }
        root->val = values[root->val];
        change(root->right, values);
        change(root->left, values);
    }

    void inorder(TreeNode* root, vector<int> &all_values)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, all_values);
        all_values.push_back(root->val);
        inorder(root->right, all_values);
    }
};