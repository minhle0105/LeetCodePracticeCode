#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<Node*> q;
        unordered_map<Node*, int> node_to_level;
        map<int, vector<int>> level_to_node;

        q.push(root);
        node_to_level[root] = 1;
        level_to_node[1].push_back(root->val);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (auto child : curr->children)
            {
                if (child != nullptr)
                {
                    q.push(child);
                    node_to_level[child] = node_to_level[curr] + 1;
                    level_to_node[node_to_level[child]].push_back(child->val);
                }
            }
        }

        for (const auto &pair : level_to_node)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};
