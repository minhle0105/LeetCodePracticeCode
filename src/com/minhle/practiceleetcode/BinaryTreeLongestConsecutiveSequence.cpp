#include <algorithm>

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
    int longestConsecutive(TreeNode* root) {
        return recursive(root, nullptr, 0);
    }
    int recursive(TreeNode* curr, TreeNode* prev, int length)
    {
        if (curr == nullptr)
        {
            return length;
        }
        int current_length = prev != nullptr && curr->val == prev->val + 1 ? length + 1 : 1;
        int right = recursive(curr->right, curr, current_length);
        int left = recursive(curr->left, curr, current_length);
        return max(current_length, max(right, left));
    }
};