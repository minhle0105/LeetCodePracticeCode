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
    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        vector<int> nums;
        string curr;
        recursive(root, curr, nums);
        int res = 0;
        for (int num : nums)
        {
            res += num;
        }
        return res;
    }

private:
    void recursive(TreeNode *root, string &curr, vector<int> &nums)
    {
        curr += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            nums.push_back(binary_string_to_int(curr));
            return;
        }
        if (root->left != nullptr)
        {
            recursive(root->left, curr, nums);
            curr.pop_back();
        }
        if (root->right != nullptr)
        {
            recursive(root->right, curr, nums);
            curr.pop_back();
        }
    }

    int binary_string_to_int(const string &binary)
    {
        int p = 0;
        int res = 0;
        for (int i = binary.size() - 1; i >= 0; --i)
        {
            res += (binary.at(i) - '0') * pow(2, p);
            ++p;
        }
        return res;
    }
};