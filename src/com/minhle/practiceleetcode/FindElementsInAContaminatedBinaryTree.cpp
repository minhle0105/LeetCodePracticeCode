#include <unordered_set>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    FindElements(TreeNode* root) {
        rebuild_tree(root, 0);
    }

    bool find(int target) {
        return values.find(target) != values.end();
    }
private:
    void rebuild_tree(TreeNode* root, int value)
    {
        values.insert(value);
        root->val = value;
        if (root->left != nullptr)
        {
            rebuild_tree(root->left, (2 * value) + 1);
        }
        if (root->right != nullptr)
        {
            rebuild_tree(root->right, (2 * value) + 2);
        }
    }
    unordered_set<int> values;
};
