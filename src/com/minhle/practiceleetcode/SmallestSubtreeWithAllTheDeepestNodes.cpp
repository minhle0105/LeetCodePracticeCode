class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> deepest_nodes;
        unordered_map<TreeNode*, int> level;
        dfs(root, level, -1);
        int deepest_level = level[root];
        for (const auto &pair : level)
        {
            deepest_level = max(deepest_level, pair.second);
        }
        for (const auto &pair : level)
        {
            if (pair.second == deepest_level)
            {
                deepest_nodes.push_back(pair.first);
            }
        }
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] = nullptr;
        dfs(root, parents);
        vector<unordered_set<TreeNode*>> traces;
        for (const auto node : deepest_nodes)
        {
            auto curr = parents[node];
            unordered_set<TreeNode*> this_parents;
            this_parents.insert(node);
            while (curr != nullptr)
            {
                this_parents.insert(curr);
                curr = parents[curr];
            }
            traces.push_back(this_parents);
        }
        vector<TreeNode*> contains;
        for (const auto node : traces[0])
        {
            bool contains_all = true;
            for (int j = 1; j < traces.size(); ++j)
            {
                if (traces[j].find(node) == traces[j].end())
                {
                    contains_all = false;
                    break;
                }
            }
            if (contains_all)
            {
                contains.push_back(node);
            }
        }
        int d = level[contains.front()];
        for (const auto node : contains)
        {
            d = max(d, level[node]);
        }
        for (const auto node : contains)
        {
            if (level[node] == d)
            {
                return node;
            }
        }
        return nullptr;
    }

    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents)
    {
        if (!root)
        {
            return;
        }
        if (root->left)
        {
            parents[root->left] = root;
            dfs(root->left, parents);
        }
        if (root->right)
        {
            parents[root->right] = root;
            dfs(root->right, parents);
        }

    }

    void dfs(TreeNode* root, unordered_map<TreeNode*, int> &level, int prev_level)
    {
        if (!root)
        {
            return;
        }
        level[root] = prev_level + 1;
        if (root->left)
        {
            dfs(root->left, level, level[root]);
        }
        if (root->right)
        {
            dfs(root->right, level, level[root]);
        }
    }
};
