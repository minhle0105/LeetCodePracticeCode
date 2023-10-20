#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n, vector<int>{});
        vector<int> outDegrees(n, 0);
        unordered_map<int, vector<int>> graph;
        for (const auto &edge : edges)
        {
            graph[edge.back()].push_back(edge.front());
            ++outDegrees.at(edge.back());
        }
        for (int i = 0; i < outDegrees.size(); ++i)
        {
            if (outDegrees.at(i) != 0)
            {
                res.at(i) = bfs(graph, i);
            }
        }
        return res;
    }
    
    vector<int> bfs(unordered_map<int, vector<int>> &graph, int source)
    {
        vector<int> visited_points;
        queue<int> q;
        unordered_set<int> visited;

        q.push(source);
        visited.insert(source);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int neighbor : graph[curr])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    visited_points.push_back(neighbor);
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        sort(visited_points.begin(), visited_points.end());
        return visited_points;
    }
};
