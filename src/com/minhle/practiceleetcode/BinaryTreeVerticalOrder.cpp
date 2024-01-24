#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr)
        {
            return vector<vector<int>>{};
        }
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode*, int> node_to_col;
        map<int, vector<int>> col_to_node;

        q.push(root);
        visited.insert(root);
        node_to_col[root] = 0;
        col_to_node[0].push_back(root->val);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            auto curr_col = node_to_col[curr];

            if (curr->left != nullptr)
            {
                if (visited.find(curr->left) == visited.end())
                {
                    visited.insert(curr->left);
                    q.push(curr->left);
                    node_to_col[curr->left] = curr_col - 1;
                    col_to_node[curr_col - 1].push_back(curr->left->val);
                }
            }

            if (curr->right != nullptr)
            {
                if (visited.find(curr->right) == visited.end())
                {
                    visited.insert(curr->right);
                    q.push(curr->right);
                    node_to_col[curr->right] = curr_col + 1;
                    col_to_node[curr_col + 1].push_back(curr->right->val);
                }
            }
        }

        vector<vector<int>> res;
        for (const auto &pair : col_to_node)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};
