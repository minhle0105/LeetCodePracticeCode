#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     ~TreeNode() = default;
};

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
        {
            return root;
        }

        unordered_map<int, queue<int>> even_level_to_node;
        unordered_map<int, stack<int>> odd_level_to_node;

        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        even_level_to_node[0].push(root->val);
        int depth = 0;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            auto node = curr.first;
            auto level = curr.second;
            if (node->left != nullptr)
            {
                q.emplace(node->left, level + 1);
                if (level % 2 == 0)
                {
                    odd_level_to_node[level + 1].push(node->left->val);
                }
                else
                {
                    even_level_to_node[level + 1].push(node->left->val);
                }
                depth = max(depth, level + 1);
            }
            if (node->right != nullptr)
            {
                q.emplace(node->right, level + 1);
                if (level % 2 == 0)
                {
                    odd_level_to_node[level + 1].push(node->right->val);
                }
                else
                {
                    even_level_to_node[level + 1].push(node->right->val);
                }
                depth = max(depth, level + 1);
            }
        }

        build_tree(root, even_level_to_node, odd_level_to_node, depth, 0);
        return root;
    }

    void build_tree(TreeNode *root, unordered_map<int, queue<int>> &even_levels, unordered_map<int, stack<int>> &odd_levels, int depth, int current_level)
    {
        if (current_level == depth)
        {
            return;
        }
        int next_level = current_level + 1;
        if (next_level % 2 == 0)
        {
            root->left->val = even_levels[next_level].front();
            even_levels[next_level].pop();
            root->right->val = even_levels[next_level].front();
            even_levels[next_level].pop();
        }
        else
        {
            root->left->val = odd_levels[next_level].top();
            odd_levels[next_level].pop();
            root->right->val = odd_levels[next_level].top();
            odd_levels[next_level].pop();
        }
        build_tree(root->left, even_levels, odd_levels, depth, current_level + 1);
        build_tree(root->right, even_levels, odd_levels, depth, current_level + 1);
    }
};