#include <vector>
#include <utility>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>{});
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (visited[i])
            {
                continue;
            }
            res += bfs(graph, i, visited) ? 1 : 0;
        }
        return res;
    }

    bool bfs(const vector<vector<int>> &graph, int source, vector<bool> &visited)
    {
        queue<int> q;
        q.push(source);
        visited[source] = true;

        vector<int> nodes_in_this_component;
        nodes_in_this_component.push_back(source);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int neighbor : graph[curr])
            {
                if (!visited[neighbor])
                {
                    nodes_in_this_component.push_back(neighbor);
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        set<pair<int, int>> edges;
        for (int node : nodes_in_this_component)
        {
            for (int neighbor : graph[node])
            {
                pair<int, int> edge = {min(node, neighbor), max(node, neighbor)};
                edges.insert(edge);
            }
        }
        int nEdges = edges.size();
        int nNodes = nodes_in_this_component.size();
        return nEdges == (nNodes * (nNodes - 1)) / 2;
    }
};
