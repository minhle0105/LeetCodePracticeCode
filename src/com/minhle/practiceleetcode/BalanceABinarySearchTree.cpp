class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        dfs(root, values);
        return recursive(values, 0, values.size() - 1);
    };

    TreeNode* recursive(const vector<int> &values, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(values[mid]);
        root->left = recursive(values, left, mid - 1);
        root->right = recursive(values, mid + 1, right);
        return root;
    }

    void dfs(TreeNode *curr, vector<int> &values)
    {
        if (!curr)
        {
            return;
        }
        dfs(curr->left, values);
        values.push_back(curr->val);
        dfs(curr->right, values);
    }
};
