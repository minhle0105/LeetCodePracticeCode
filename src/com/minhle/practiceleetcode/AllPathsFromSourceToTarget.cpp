#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> current_path = {0};
        dfs(graph, 0, current_path, res);
        return res;
    }

    void dfs(const vector<vector<int>>& graph, int curr, vector<int>& current_path, vector<vector<int>>& res)
    {
        int n = graph.size();

        if (curr == n - 1)
        {
            res.push_back(current_path);
        }
        else
        {
            for (int neighbor : graph[curr])
            {
                current_path.push_back(neighbor);
                dfs(graph, neighbor, current_path, res);
                current_path.pop_back();
            }
        }
    }
};