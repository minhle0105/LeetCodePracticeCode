class Solution {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unordered_map<int, vector<int>> graph;
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> res;

        for (const auto &q : query)
        {
            int src = q[0];
            int dst = q[1];
            int target = q[2];

            auto all_nodes = get_nodes_on_path(graph, src, dst);

            res.push_back(bfs(graph, target, all_nodes));
        }
        return res;
    }

    int bfs(unordered_map<int, vector<int>> &graph, int src, const vector<int> &all_targets)
    {
        queue<int> q;
        unordered_set<int> visited;
        unordered_map<int, int> distances;

        q.push(src);
        visited.insert(src);
        distances[src] = 0;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (int neighbor : graph[curr])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    q.push(neighbor);
                    visited.insert(neighbor);
                    distances[neighbor] = distances[curr] + 1;
                }
            }
        }

        int min_dist = INT_MAX;
        int min_node = -1;

        for (int node : all_targets)
        {
            if (distances[node] < min_dist)
            {
                min_dist = distances[node];
                min_node = node;
            }
        }
        return min_node;
    }

    vector<int> get_nodes_on_path(unordered_map<int, vector<int>> &graph, int src, int dst)
    {
        queue<int> q;
        unordered_set<int> visited;
        unordered_map<int, int> prev;

        q.push(src);
        visited.insert(src);
        prev[src] = -1;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (int neighbor : graph[curr])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    q.push(neighbor);
                    visited.insert(neighbor);
                    prev[neighbor] = curr;
                }
            }
        }
        vector<int> paths;
        int curr = dst;
        while (curr != -1)
        {
            paths.push_back(curr);
            curr = prev[curr];
        }
        reverse(paths.begin(), paths.end());
        return paths;
    }
};
