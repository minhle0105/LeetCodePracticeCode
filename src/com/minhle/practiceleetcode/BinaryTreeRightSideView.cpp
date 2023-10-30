#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            res.push_back(root->val);
            return res;
        }
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> node_to_level;
        map<int, vector<int>> level_to_node;

        q.push(root);
        node_to_level[root] = 1;
        level_to_node[1].push_back(root->val);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr->left != nullptr)
            {
                q.push(curr->left);
                node_to_level[curr->left] = node_to_level[curr] + 1;
                level_to_node[node_to_level[curr->left]].push_back(curr->left->val);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
                node_to_level[curr->right] = node_to_level[curr] + 1;
                level_to_node[node_to_level[curr->right]].push_back(curr->right->val);
            }
        }

        for (const auto &pair : level_to_node)
        {
            res.push_back(pair.second.back());
        }
        return res;
    }
};
