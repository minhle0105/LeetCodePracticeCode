#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> graph;
        int n = quiet.size();
        for (int i = 0; i < n; ++i)
        {
            graph[i] = vector<int>{};
        }
        for (const auto &rich : richer)
        {
            graph[rich.back()].push_back(rich.front());
        }
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            if (graph[i].empty())
            {
                res.push_back(i);
                continue;
            }
            res.push_back(bfs(graph, quiet, i));
        }
        return res;
    }
    
    int bfs(unordered_map<int, vector<int>> &graph, vector<int> &quiet, int source)
    {
        pair<int, int> res = {source, quiet.at(source)};
        queue<int> q;
        unordered_set<int> visited;
        q.push(source);
        visited.insert(source);
        
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int richer : graph[curr])
            {
                if (visited.find(richer) == visited.end())
                {
                    visited.insert(richer);
                    q.push(richer);
                    if (quiet.at(richer) < res.second)
                    {
                        res.second = quiet.at(richer);
                        res.first = richer;
                    }
                }
            }
        }
        return res.first;
    }
};
