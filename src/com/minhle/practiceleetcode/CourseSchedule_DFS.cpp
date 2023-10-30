#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (const auto &pair : prerequisites)
        {
            graph[pair.back()].push_back(pair.front());
        }
        unordered_set<int> visited;
        unordered_set<int> st;
        for (int i = 0; i < numCourses; ++i)
        {
            if (visited.find(i) == visited.end())
            {
                if (has_cycle(graph, visited, i, st))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool has_cycle(unordered_map<int, vector<int>> &graph, unordered_set<int> &visited, int curr, unordered_set<int> &st)
    {
        st.insert(curr);
        visited.insert(curr);
        for (const auto &course : graph[curr])
        {
            if (visited.find(course) == visited.end())
            {
                if (has_cycle(graph, visited, course, st))
                {
                    return true;
                }
            }
            else
            {
                if (st.find(course) != st.end())
                {
                    return true;
                }
            }
        }
        st.erase(curr);
        return false;
    }
};
