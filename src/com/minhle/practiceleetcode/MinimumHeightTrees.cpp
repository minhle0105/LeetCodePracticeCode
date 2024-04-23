class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.empty())
        {
            return vector<int>{0};
        }
        unordered_map<int, vector<int>> graph;
        vector<int> degrees(n, 0);
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);

            ++degrees[edge[0]];
            ++degrees[edge[1]];
        }

        queue<int> q;
        for (int i = 0; i < degrees.size(); ++i)
        {
            if (degrees[i] == 1)
            {
                q.push(i);
            }
        }
        while (n > 2)
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                int curr = q.front();
                q.pop();
                --n;
                for (int neighbor : graph[curr])
                {
                    --degrees[neighbor];
                    if (degrees[neighbor] == 1)
                    {
                        q.push(neighbor);
                    }
                }
            }
        }
        vector<int> res;
        res.reserve(q.size());

        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
