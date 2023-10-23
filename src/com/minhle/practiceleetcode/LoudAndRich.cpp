#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int, vector<int>> graph;
        vector<int> res(n, -1);

        for (const auto &rich : richer)
        {
            graph[rich.back()].push_back(rich.front());
        }
        unordered_set<int> visited;
        for (int i = 0; i < n; ++i)
        {
            dfs(graph, quiet, res, visited, i);
        }

        return res;
    }

    int dfs(unordered_map<int, vector<int>> &graph, const vector<int>& quiet, vector<int>& res, unordered_set<int> &visited, int source) {
        if (res[source] != -1)
        {
            return res[source];
        }
        if (res[source] == -1)
        {
            res[source] = source;
        }
        visited.insert(source);
        int loudest = source;
        for (int richer : graph[source])
        {
            if (visited.find(richer) == visited.end())
            {
                int candidate = dfs(graph, quiet, res, visited, richer);
                if (quiet[candidate] < quiet[loudest])
                {
                    loudest = candidate;
                    res[source] = candidate;
                }
            }
        }
        visited.erase(source);
        return res[source];
    }
};
