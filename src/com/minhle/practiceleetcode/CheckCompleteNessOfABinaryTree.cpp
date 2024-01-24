#include "AllNecessaryHeaders.h"
#include "TreeNode.h"

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        unordered_map<int, vector<int>> levels;

        q.push({root, 0});
        levels[0].push_back(root->val);
        int last_level = 0;
        while (!q.empty())
        {
            auto node = q.front().first;
            auto level = q.front().second;
            q.pop();
            if (node->left == nullptr && node->right != nullptr)
            {
                return false;
            }
            if (node->left == nullptr)
            {
                levels[level + 1].push_back(0);
            }
            else
            {
                levels[level + 1].push_back(node->left->val);
                q.push({node->left, level + 1});
            }

            if (node->right == nullptr)
            {
                levels[level + 1].push_back(0);
            }
            else
            {
                levels[level + 1].push_back(node->right->val);
                q.push({node->right, level + 1});
            }
            last_level = max(last_level, level + 1);
        }
        levels.erase(last_level);
        --last_level;


        // check if non-null node are as leftmost as possible
        for (const auto &pair : levels)
        {
            for (int i = 0; i < pair.second.size() - 1; ++i)
            {
                if (pair.second[i] == 0)
                {
                    for (int j = i + 1; j < pair.second.size(); ++j)
                    {
                        if (pair.second[j] != 0)
                        {
                            return false;
                        }
                    }
                }
            }
        }

        // check if each level is completed
        unordered_map<int, int> nodes_per_level;
        for (const auto &pair : levels)
        {
            int n_nodes = 0;
            for (auto node_val : pair.second)
            {
                if (node_val != 0)
                {
                    ++n_nodes;
                }
            }
            nodes_per_level[pair.first] = n_nodes;
        }

        for (const auto &pair : nodes_per_level)
        {
            long long n_nodes_should_be_this_level = pow(2, pair.first);
            int n_nodes_actual = pair.second;
            if (n_nodes_actual != n_nodes_should_be_this_level)
            {
                bool is_last_level = pair.first == last_level;
                if (!is_last_level)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
