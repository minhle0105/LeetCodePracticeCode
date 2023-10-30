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
    vector<int> trees;
    int getMinimumDifference(TreeNode* root) {
        serialize(root);
        sort(trees.begin(), trees.end());
        int res = INT_MAX;
        for (size_t i = 0; i < trees.size() - 1; ++i)
        {
            res = min_(res, abs_(trees.at(i) - trees.at(i + 1)));
        }
        return res;
    }

    void serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        trees.push_back(root->val);
        serialize(root->left);
        serialize(root->right);
    }

    int min_(int a, int b)
    {
        return a < b ? a : b;
    }

    int abs_(int x)
    {
        return x >= 0 ? x : (x) * (-1);
    }

};
