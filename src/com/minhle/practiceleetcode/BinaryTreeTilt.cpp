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
    int findTilt(TreeNode* root) {
        vector<int> tilt;
        recursive(root, tilt);
        int res = 0;
        for (int num : tilt)
        {
            res += num;
        }
        return res;
    }
private:
    int recursive(TreeNode *root, vector<int> &tilt)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left != nullptr && root->right != nullptr)
        {
            int left_sub = recursive(root->left, tilt);
            int right_sub = recursive(root->right, tilt);
            tilt.push_back(abs(left_sub - right_sub));
            return left_sub + right_sub + root->val;
        }
        if (root->left == nullptr)
        {
            int right_sub = recursive(root->right, tilt);
            tilt.push_back(abs(right_sub));
            return root->val + right_sub;
        }
        if (root->right == nullptr)
        {
            int left_sub = recursive(root->left, tilt);
            tilt.push_back(abs(left_sub));
            return root->val + left_sub;
        }
        return root->val;
    }
};
