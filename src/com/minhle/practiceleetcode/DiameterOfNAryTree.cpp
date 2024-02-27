#include "AllNecessaryHeaders.h"

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
    int diameter(Node* root) {
        unordered_map<Node*, vector<Node*>> graph;
        construct_map(root, graph);

        auto furthest_node_first_scan = bfs(root);

        unordered_set<Node*> visited;

        return dfs(furthest_node_first_scan, graph, visited) - 1;
    }

private:
    void construct_map(Node *curr, unordered_map<Node*, vector<Node*>> &graph)
    {
        if (curr == nullptr)
        {
            return;
        }
        for (auto child : curr->children)
        {
            graph[curr].push_back(child);
            graph[child].push_back(curr);
            construct_map(child, graph);
        }
    }

    Node* bfs(Node* src)
    {
        queue<Node*> q;
        unordered_map<Node*, int> distances;

        q.push(src);

        distances[src] = 0;
        int max_distance = 0;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int d = distances[curr];

            for (auto child : curr->children)
            {
                distances[child] = d + 1;
                q.push(child);
                max_distance = max(max_distance, distances[child]);
            }
        }

        for (const auto &pair : distances)
        {
            if (pair.second == max_distance)
            {
                return pair.first;
            }
        }
        return nullptr;
    }

    int dfs(Node *curr, unordered_map<Node*, vector<Node*>> &graph, unordered_set<Node*> &visited)
    {
        if (curr == nullptr)
        {
            return 0;
        }
        visited.insert(curr);
        int max_distance = 0;
        for (auto neighbor : graph[curr])
        {
            if (visited.find(neighbor) == visited.end())
            {
                max_distance = max(max_distance, dfs(neighbor, graph, visited));
            }
        }
        return 1 + max_distance;
    }
};
