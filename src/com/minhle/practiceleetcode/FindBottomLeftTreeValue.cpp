#include <queue>
#include <utility>
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
    int findBottomLeftValue(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        unordered_map<int, vector<int>> level_to_nodes;
        int max_level = 0;
        level_to_nodes[0].push_back(root->val);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            auto node = curr.first;
            auto level = curr.second;

            if (node->left != nullptr)
            {
                q.push({node->left, level + 1});
                level_to_nodes[level + 1].push_back(node->left->val);
                max_level = max(max_level, level + 1);
            }
            if (node->right != nullptr)
            {
                q.push({node->right, level + 1});
                level_to_nodes[level + 1].push_back(node->right->val);
                max_level = max(max_level, level + 1);
            }
        }
        return level_to_nodes[max_level].front();
    }
};