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
    int longestZigZag(TreeNode* root) {
        cache.clear();
        zigzag(root->left, true);
        zigzag(root->right, false);
        int res = dfs(root);
        return res;
    }

private:
    unordered_map<TreeNode*, int> cache;

    int dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int zig_zag_here = max(zigzag(root->left, true), zigzag(root->right, false));
        int zig_zag_from_left = dfs(root->left);
        int zig_zag_from_right = dfs(root->right);
        return max(zig_zag_here, max(zig_zag_from_left, zig_zag_from_right));
    }

    int zigzag(TreeNode* root, bool going_left)
    {
        if (cache.find(root) != cache.end())
        {
            return cache[root];
        }
        if (root == nullptr)
        {
            return 0;
        }
        if (going_left)
        {
            cache[root] = 1 + zigzag(root->right, false);
            return cache[root];
        }
        cache[root] = 1 + zigzag(root->left, true);
        return cache[root];
    }
};
