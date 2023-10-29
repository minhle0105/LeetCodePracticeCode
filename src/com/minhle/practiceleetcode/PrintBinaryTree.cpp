#include <vector>
#include <string>

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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = find_depth(root) - 1;
        int m = height + 1;
        int n = pow(2, height + 1) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        place(root, res, 0, (n - 1) / 2, height);
        return res;
    }

    int find_depth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + max(find_depth(root->left), find_depth(root->right));
    }

    void place(TreeNode *root, vector<vector<string>> &res, int r, int c, int height)
    {
        if (root == nullptr)
        {
            return;
        }
        res[r][c] = to_string(root->val);
        int left_r = r + 1;
        int left_c = c - pow(2, height - r - 1);
        int right_r = r + 1;
        int right_c = c + pow(2, height - r - 1);

        place(root->left, res, left_r, left_c, height);
        place(root->right, res, right_r, right_c, height);
    }
};
