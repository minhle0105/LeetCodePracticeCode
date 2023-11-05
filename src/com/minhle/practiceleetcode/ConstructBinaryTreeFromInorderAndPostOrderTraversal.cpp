#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> val_ind;
        for (int i = 0; i < inorder.size(); ++i)
        {
            val_ind[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, 0, inorder.size(), val_ind);
    }

    TreeNode* build(const vector<int> &inorder, const vector<int> &postorder, int a, int b, int nElements, unordered_map<int, int> &val_ind)
    {
        if (nElements == 0)
        {
            return nullptr;
        }
        auto curr = new TreeNode(postorder[b + nElements - 1]);
        int curr_pos = val_ind[curr->val];
        int nElementLeft = curr_pos - a; // inorder -> left curr right
        curr->left = build(inorder, postorder, a, b , nElementLeft, val_ind);
        int nElementRight = nElements - nElementLeft - 1; // left right curr
        curr->right = build(inorder, postorder, curr_pos + 1, b + nElementLeft, nElementRight, val_ind);

        return curr;
    }
};
