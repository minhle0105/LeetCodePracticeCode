#include "AllNecessaryHeaders.h"
#include "TreeNode.h"

class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        auto source = find_node_k(root, k);
        if (is_leaf(source))
        {
            return source->val;
        }
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        construct_graph(nullptr, root, graph);
        return bfs(source, graph);
    }
private:
    TreeNode* find_node_k(TreeNode* root, int k)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val == k)
        {
            return root;
        }
        auto left = find_node_k(root->left, k);
        auto right = find_node_k(root->right, k);
        return left != nullptr ? left : right;
    }

    void construct_graph(TreeNode* root, TreeNode* curr, unordered_map<TreeNode*, vector<TreeNode*>> &graph)
    {
        if (curr == nullptr)
        {
            return;
        }
        if (root != nullptr)
        {
            graph[root].push_back(curr);
            graph[curr].push_back(root);
        }
        construct_graph(curr, curr->left, graph);
        construct_graph(curr, curr->right, graph);
    }

    bool is_leaf(TreeNode* node)
    {
        return node->left == nullptr && node->right == nullptr;
    }

    int bfs(TreeNode* source, unordered_map<TreeNode*, vector<TreeNode*>> &graph)
    {
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(source);
        visited.insert(source);

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            for (auto neighbor : graph[node])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    if (is_leaf(neighbor))
                    {
                        return neighbor->val;
                    }
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return -1;
    }
};