#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<int> degrees(edges.size() + 1, 0);
        for (const auto &edge : edges)
        {
            graph[edge.front()].push_back(edge.back());
            graph[edge.back()].push_back(edge.front());
            ++degrees.at(edge.back());
            ++degrees.at(edge.front());
        }   

        int source = 0;
        for (int i = 0; i < degrees.size(); ++i)
        {
            if (degrees.at(i) == 1)
            {
                source = i;
                break;
            }
        }
        pair<int, int> first_round = bfs(graph, source);
        pair<int, int> second_round = bfs(graph, first_round.first);

        return second_round.second;
    }

    pair<int, int> bfs(unordered_map<int, vector<int>> &graph, int source)
    {
        unordered_map<int, int> levels;
        unordered_set<int> visited;
        queue<int> st;
        levels[source] = 0;
        visited.insert(source);
        st.push(source);

        while (!st.empty())
        {
            int curr = st.front();
            st.pop();
            for (int neighbor : graph[curr])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    visited.insert(neighbor);
                    st.push(neighbor);
                    levels[neighbor] = levels[curr] + 1;
                }
            }
        }

        pair<int, int> res;
        for (const auto &level : levels)
        {
            if (level.second > res.second)
            {
                res.second = level.second;
                res.first = level.first;
            }
        }
        return res;
    }
};
