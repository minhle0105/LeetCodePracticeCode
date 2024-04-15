class Solution {
public:
    unordered_set<TreeNode*> leaves;
    unordered_map<TreeNode*, TreeNode*> parents;

    string smallestFromLeaf(TreeNode* root) {
        leaves.clear();
        parents.clear();

        dfs(root, nullptr);
        priority_queue<string, vector<string>, greater<string>> all_paths;
        for (const auto leave : leaves)
        {
            string path;
            auto curr = leave;
            while (curr != nullptr)
            {
                path += static_cast<char>(curr->val + 97);
                curr = parents[curr];
            }
            all_paths.push(path);
        }
        return all_paths.top();
    }

    void dfs(TreeNode* curr, TreeNode* prev)
    {
        if (!curr)
        {
            return;
        }
        if (!curr->left && !curr->right)
        {
            leaves.insert(curr);
        }
        parents[curr] = prev;
        dfs(curr->left, curr);
        dfs(curr->right, curr);
    }
};
