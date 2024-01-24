#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

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
    bool isEvenOddTree(TreeNode* root) {
        if (root->val % 2 == 0)
        {
            return false;
        }
        unordered_map<int, vector<int>> level_nodes;
        queue<pair<TreeNode*, int>> q;

        q.emplace(root, 0);
        level_nodes[0].push_back(root->val);

        while (!q.empty())
        {
            auto node = q.front().first;
            auto level = q.front().second;
            q.pop();

            bool next_level_is_even = (level + 1) % 2 == 0;

            if (node->left != nullptr)
            {
                if (next_level_is_even)
                {
                    if ((node->left->val % 2 == 0) ||
                        (!level_nodes[level + 1].empty() && node->left->val <= level_nodes[level + 1].back()))
                    {
                        return false;
                    }
                }
                else
                {
                    if ((node->left->val % 2 != 0) ||
                        (!level_nodes[level + 1].empty() && node->left->val >= level_nodes[level + 1].back()))
                    {
                        return false;
                    }
                }
                q.emplace(node->left, level + 1);
                level_nodes[level + 1].push_back(node->left->val);
            }

            if (node->right != nullptr)
            {
                if (next_level_is_even)
                {
                    if ((node->right->val % 2 == 0) ||
                        (!level_nodes[level + 1].empty() && node->right->val <= level_nodes[level + 1].back()))
                    {
                        return false;
                    }
                }
                else
                {
                    if ((node->right->val % 2 != 0) ||
                        (!level_nodes[level + 1].empty() && node->right->val >= level_nodes[level + 1].back()))
                    {
                        return false;
                    }
                }
                q.emplace(node->right, level + 1);
                level_nodes[level + 1].push_back(node->right->val);
            }
        }
        return true;
    }
};