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
        for (const auto &query : queries)
        {
            unordered_set<int> visited;
            res.push_back(dfs(graph, visited, query.front(), query.back()));
        } 
        return res;
    }

    bool dfs(unordered_map<int, vector<int>> &graph, unordered_set<int> &visited, int source, int dst)
    {
        if (source == dst)
        {
            return true;
        }
        visited.insert(source);
        for (int course : graph[source])
        {
            if (visited.find(course) == visited.end())
            {
                if (dfs(graph, visited, course, dst))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
