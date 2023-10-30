#include <queue>
#include <utility>
#include <map>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int max_width = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int number_of_nodes_at_this_level = q.size();
            auto left_most_position_with_valid_node = q.front().second;
            for (int i = 0; i < number_of_nodes_at_this_level; i++)
            {
                auto node = q.front().first;
                auto idx = q.front().second;
                q.pop();
                if (node->left != nullptr)
                {
                    q.push({node->left, 2ULL * idx});
                }
                if (node->right != nullptr)
                {
                    q.push({node->right, 2ULL * idx + 1});
                }
                max_width = max(max_width, static_cast<int>(idx - left_most_position_with_valid_node + 1));
            }
        }
        return max_width;
    }
};