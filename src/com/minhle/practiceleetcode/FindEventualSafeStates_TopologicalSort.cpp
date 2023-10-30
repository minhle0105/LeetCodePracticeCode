#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
        vector<int> degrees(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i)
        {
            for (int j = 0; j < graph.at(i).size(); ++j)
            {
                adj[graph.at(i).at(j)].push_back(i);
                ++degrees.at(i);
            }
        }

        queue<int> q;
        vector<bool> safe(graph.size());

        for (int i = 0; i < degrees.size(); ++i)
        {
            if (degrees.at(i) == 0)
            {
                q.push(i);
                safe.at(i) = true;
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr])
            {
                --degrees.at(neighbor);
                if (degrees.at(neighbor) == 0)
                {
                    safe.at(neighbor) = true;
                    q.push(neighbor);
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < safe.size(); ++i)
        {
            if (safe.at(i))
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
