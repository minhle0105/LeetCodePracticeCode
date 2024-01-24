#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> res(k, vector<int>(k, 0));
        vector<int> rows = topo(rowConditions, k);
        vector<int> cols = topo(colConditions, k);
        if (rows.size() != k || cols.size() != k)
        {
            return vector<vector<int>>{};
        }

        for (int i = 0; i < rows.size(); ++i)
        {
            int element = rows.at(i);
            int r = i;
            for (int c = 0; c < cols.size(); ++c)
            {
                if (cols.at(c) == element)
                {
                    res.at(r).at(c) = element;
                    break;
                }
            }
        }
        return res;   
    }

    vector<int> topo(const vector<vector<int>> &conditions, int k)
    {
        unordered_map<int, vector<int>> graph;
        vector<int> degrees(k + 1, 0);
        for (const auto &condition : conditions)
        {
            graph[condition.front()].push_back(condition.back());
            ++degrees.at(condition.back());
        }

        queue<int> q;
        vector<int> orders;

        for (int i = 1; i < degrees.size(); ++i)
        {
            if (degrees.at(i) == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            orders.push_back(curr);

            for (int num : graph[curr])
            {
                --degrees.at(num);
                if (degrees.at(num) == 0)
                {
                    q.push(num);
                }
            }
        }
        return orders;
    }
};
