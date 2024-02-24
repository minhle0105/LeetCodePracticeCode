class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (const auto &flight : flights)
        {
            int start = flight[0];
            int end = flight[1];
            int distance = flight[2];

            graph[start].emplace_back(end, distance);
        }
        vector<vector<int>> dp(n, vector<int>(k + 2, -1));
        auto res = dfs(graph, src, dst, k + 1, dp);
        return res == INT_MAX ? -1 : res;
    }

    int dfs(unordered_map<int, vector<pair<int, int>>> &graph, int src, const int dst, int remaining_stop, 
            vector<vector<int>> &dp)
    {
        if (src == dst)
        {
            return 0;
        }
        if (dp[src][remaining_stop] != -1)
        {
            return dp[src][remaining_stop];
        }

        int local_res = INT_MAX;
        if (remaining_stop > 0)
        {
            for (const auto &neighbor : graph[src])
            {
                int id = neighbor.first;
                int distance = neighbor.second;
                int res = dfs(graph, id, dst, remaining_stop - 1, dp);
                if (res != INT_MAX)
                {
                    local_res = min(local_res, distance + res);
                }
            }
        }
        dp[src][remaining_stop] = local_res;
        return dp[src][remaining_stop];
    }
};
