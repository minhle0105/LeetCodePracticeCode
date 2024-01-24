#include <queue>
#include <unordered_map>
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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if (root == u)
        {
            return nullptr;
        }
        int level_of_u = -1;

        queue<pair<TreeNode*, int>> q;
        unordered_map<int, vector<TreeNode*>> levels;
        q.push({root, 0});
        levels[0].push_back(root);

        while (!q.empty())
        {
            auto curr = q.front();
            auto node = curr.first;
            auto level = curr.second;

            q.pop();

            if (node == u)
            {
                level_of_u = level;
            }

            if (node->left != nullptr)
            {
                q.push({node->left, level + 1});
                levels[level + 1].push_back(node->left);
            }

            if (node->right != nullptr)
            {
                q.push({node->right, level + 1});
                levels[level + 1].push_back(node->right);
            }
        }
        int n = levels[level_of_u].size();
        for (int i = 0; i < n; ++i)
        {
            if (levels[level_of_u][i] == u)
            {
                return i == n - 1 ? nullptr : levels[level_of_u][i + 1];;
            }
        }
        return nullptr;
    }
};
