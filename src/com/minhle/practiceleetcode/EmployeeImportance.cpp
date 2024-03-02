#include "AllNecessaryHeaders.h"
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    unordered_map<int, int> importances;
    unordered_map<int, vector<int>> graph;

    int getImportance(vector<Employee*> employees, int id) {
        importances.clear();
        graph.clear();

        for (const auto employee : employees)
        {
            importances[employee->id] = employee->importance;
            for (int s : employee->subordinates)
            {
                graph[employee->id].push_back(s);
            }
        }
        return dfs(id);
    }

    int dfs(int id)
    {
        int res = importances[id];
        for (int s : graph[id])
        {
            res += dfs(s);
        }
        return res;
    }
};
