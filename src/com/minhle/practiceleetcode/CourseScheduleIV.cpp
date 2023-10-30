#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;
        for (const auto &r : prerequisites)
        {
            graph[r.front()].push_back(r.back());
        }
        vector<bool> res;
        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < numCourses; ++i)
        {
            bfs(graph, i, isReachable);
        }
        for (const auto &query : queries)
        {
            int source = query.front();
            int dest = query.back();
            res.push_back(isReachable.at(source).at(dest));
        }
        return res;
    }

    void bfs(unordered_map<int, vector<int>> &graph, int source, vector<vector<bool>> &isReachable)
    {
        queue<int> q;
        unordered_set<int> visited;
        q.push(source);
        visited.insert(source);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int course : graph[curr])
            {
                if (visited.find(course) == visited.end())
                {
                    isReachable.at(source).at(course) = true;
                    visited.insert(course);
                    q.push(course);
                }
            }
        }
    }
};