#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < bombs.size(); ++i)
        {
            graph[i] = vector<int>{};
        }
        for (int i = 0; i < bombs.size() - 1; ++i)
        {
            pair<int, int> bomb1 = {bombs[i][0], bombs[i][1]};
            int radius1 = bombs[i][2];
            for (int j = i + 1; j < bombs.size(); ++j)
            {
                pair<int, int> bomb2 = {bombs[j][0], bombs[j][1]};
                int radius2 = bombs[j][2];
                double distance = calculate_distance(bomb1, bomb2);
                if (distance <= radius1)
                {
                    graph[i].push_back(j);
                }
                if (distance <= radius2)
                {
                    graph[j].push_back(i);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < bombs.size(); ++i)
        {
            res = max(bfs(graph, i), res);
        }
        return res;
    }

    int bfs(unordered_map<int, vector<int>> &graph, int source)
    {
        queue<int> q;
        unordered_set<int> visited;
        q.push(source);
        visited.insert(source);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int next : graph[curr])
            {
                if (visited.find(next) == visited.end())
                {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return visited.size();
    }

    double calculate_distance(const pair<int, int> &point1, const pair<int, int> &point2)
    {
        int x1 = point1.first;
        int y1 = point1.second;
        int x2 = point2.first;
        int y2 = point2.second;

        return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    }
};
