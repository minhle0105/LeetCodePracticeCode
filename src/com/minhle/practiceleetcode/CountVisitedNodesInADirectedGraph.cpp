class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i)
        {
            if (res[i] == -1)
            {
                dfs(edges, i, visited, res);
            }
        }
        return res;
    }

    void dfs(const vector<int> &edges, int curr, vector<int> &visited, vector<int> &res)
    {
        if (res[curr] != -1)
        {
            return;
        }
        if (visited[curr] == 1)
        {
            unordered_set<int> cycles;
            cycles.insert(curr);
            auto temp = edges[curr];
            while (temp != curr)
            {
                cycles.insert(temp);
                temp = edges[temp];
            }
            for (int node : cycles)
            {
                res[node] = cycles.size();
            }
            return;
        }
        visited[curr] = 1;
        dfs(edges, edges[curr], visited, res);
        if (res[curr] == -1)
        {
            res[curr] = 1 + res[edges[curr]];
        }
    }
};
