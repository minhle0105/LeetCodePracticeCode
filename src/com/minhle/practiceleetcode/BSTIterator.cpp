#include <stack>

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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        dfs_leftmost(root);
    }

    int next() {
        auto top_node = st.top();
        st.pop();
        if (top_node->right != nullptr)
        {
            dfs_leftmost(top_node->right);
        }
        return top_node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
private:
    stack<TreeNode*> st;

    void dfs_leftmost(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        st.push(root);
        dfs_leftmost(root->left);
    }
};

