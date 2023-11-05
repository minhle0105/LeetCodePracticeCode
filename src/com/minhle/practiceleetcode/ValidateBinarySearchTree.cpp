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
    bool isValidBST(TreeNode* root) {
        auto res = dfs(root);
        return res.front() == 1;
    }

    // return value as
    // [0] is either 1 (true) or 0 (false) --> bool whether a subtree is valid
    // [1] is the min value of the subtree
    // [2] is the max value of the subtree
    vector<int> dfs(TreeNode* root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            // if getting all the way here to a leaf node, we don't see any false case --> this is true
            return vector<int>{1, root->val, root->val};
        }
        vector<int> res = {1, root->val, root->val};
        if (root->left != nullptr)
        {
            vector<int> left = dfs(root->left);
            // if either left is invalid or the max of left subtree is >= root->val
            // --> false because max of left subtree has to be strictly less than root->val
            if (left.front() == 0 || left.back() >= root->val)
            {
                return vector<int>{0, 0, 0};
            }
            // otherwise update min to min of left subtree
            res.at(1) = left.at(1);
        }

        if (root->right != nullptr)
        {
            auto right = dfs(root->right);
            if (right.front() == 0 || right.at(1) <= root->val)
            {
                return vector<int>{0, 0, 0};
            }
            res.back() = right.back();
        }
        return res;
    }
};