#include <queue>
#include <utility>
#include <unordered_map>
#include <unordered_set>
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
        {
            root->val = 0;
            return root;
        }
        queue<pair<TreeNode*, int>> q;
        unordered_map<TreeNode*, TreeNode*> child_to_parent;
        map<int, vector<TreeNode*>> level_to_nodes;
        map<int, int> level_sum;
        
        child_to_parent[root] = nullptr;
        level_to_nodes[0].push_back(root);
        level_sum[0] = root->val;
        q.push({root, 0});

        while (!q.empty())
        {
            auto node = q.front().first;
            auto level = q.front().second;
            q.pop();

            if (node->left != nullptr)
            {
                q.push({node->left, level + 1});
                child_to_parent[node->left] = node;
                level_to_nodes[level + 1].push_back(node->left);
                level_sum[level + 1] += node->left->val;
            }

            if (node->right != nullptr)
            {
                q.push({node->right, level + 1});
                child_to_parent[node->right] = node;
                level_to_nodes[level + 1].push_back(node->right);
                level_sum[level + 1] += node->right->val;
            }
        }
        unordered_map<TreeNode*, int> node_to_new_values;
        node_to_new_values[root] = 0;
        for (const auto &pair : level_to_nodes)
        {
            if (pair.first == 0)
            {
                pair.second[0]->val = 0;
            }
            else
            {
                for (int i = 0; i < pair.second.size(); ++i)
                {
                    int sum = level_sum[pair.first];
                    int val_to_subtract = 0;
                    int minus = i - 1;
                    int plus = i + 1;
                    if (minus >= 0 && is_sibling(pair.second[i], pair.second[minus], child_to_parent))
                    {
                        val_to_subtract = pair.second[minus]->val;
                    }
                    else if (plus < pair.second.size() && is_sibling(pair.second[i], pair.second[plus], child_to_parent))
                    {
                        val_to_subtract = pair.second[plus]->val;
                    }

                    sum -= pair.second[i]->val;
                    sum -= val_to_subtract;
                    node_to_new_values[pair.second[i]] = sum;
                }
            }
        }
        change_value(root, node_to_new_values);
        return root;
    }

    void change_value(TreeNode* root, unordered_map<TreeNode*, int> &node_to_new_values)
    {
        if (root == nullptr)
        {
            return;
        }
        root->val = node_to_new_values[root];
        change_value(root->left, node_to_new_values);
        change_value(root->right, node_to_new_values);
    }

    bool is_sibling(TreeNode* node1, TreeNode* node2, unordered_map<TreeNode*, TreeNode*> &child_to_parent)
    {
        return child_to_parent[node1] == child_to_parent[node2];
    }
};
