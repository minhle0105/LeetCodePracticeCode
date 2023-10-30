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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned == nullptr || original == nullptr)
        {
            return nullptr;
        }
        if (cloned->val == target->val)
        {
            return cloned;
        }
        auto left = getTargetCopy(original, cloned->left, target);
        auto right = getTargetCopy(original, cloned->right, target);
        return left == nullptr ? right : left;
    }
};