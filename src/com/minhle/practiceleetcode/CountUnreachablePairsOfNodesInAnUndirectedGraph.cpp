class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<long long> prefix_sum = {0};

        unordered_map<int, vector<int>> graph;
        for (const auto &edge : edges)
        {
            auto src = edge.front();
            auto dst = edge.back();

            graph[src].push_back(dst);
            graph[dst].push_back(src);
        }
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                prefix_sum.push_back(dfs(graph, i, visited) + prefix_sum.back());
            }
        }

        long long res = 0;
        for (int i = 1; i < prefix_sum.size() - 1; ++i)
        {
            long long num = prefix_sum[i] - prefix_sum[i - 1];
            res += (num * (prefix_sum.back() - prefix_sum[i]));
        }        
        return res;

    }

    long long dfs(unordered_map<int, vector<int>> &graph, int src, vector<bool> &visited)
    {
        if (visited[src])
        {
            return 0;
        }
        long long node_visited = 1;
        visited[src] = true;
        for (int neighbor : graph[src])
        {
            node_visited += dfs(graph, neighbor, visited);
        }
        return node_visited;
    }
};
