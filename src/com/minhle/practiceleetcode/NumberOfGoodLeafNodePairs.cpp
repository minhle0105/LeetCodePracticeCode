#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>

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
    int countPairs(TreeNode* root, int distance) {
        vector<TreeNode*> leaves;
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        find_leaves_and_build_graph(root, leaves, graph);
        int res = 0;
        for (auto leave : leaves)
        {
            res += bfs(graph, leave, distance);
        }
        return res / 2;
    }
private:
    int bfs(unordered_map<TreeNode*, vector<TreeNode*>> &graph, TreeNode* source, int distance)
    {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode*, int> levels;

        q.push(source);
        visited.insert(source);
        levels[source] = 0;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (levels[curr] + 1 > distance)
            {
                continue;
            }

            for (auto neighbor : graph[curr])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                    levels[neighbor] = levels[curr] + 1;
                }
            }
        }

        int res = 0;
        for (const auto &pair : levels)
        {
            if (pair.first != source && is_leaf(pair.first))
            {
                ++res;
            }
        }
        return res;
    }

    void find_leaves_and_build_graph(TreeNode* root, vector<TreeNode*> &leaves, unordered_map<TreeNode*, vector<TreeNode*>> &graph)
    {
        if (root == nullptr)
        {
            return;
        }
        if (is_leaf(root))
        {
            leaves.push_back(root);
            return;
        }
        if (root->left != nullptr)
        {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
        }
        if (root->right != nullptr)
        {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
        }
        find_leaves_and_build_graph(root->left, leaves, graph);
        find_leaves_and_build_graph(root->right, leaves, graph);
    }

    bool is_leaf(TreeNode* node)
    {
        return node->left == nullptr && node->right == nullptr;
    }
};