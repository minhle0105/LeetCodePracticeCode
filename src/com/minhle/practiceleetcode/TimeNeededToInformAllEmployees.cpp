#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> receivedTime;
        for (int i = 0; i < n; ++i)
        {
            graph[i] = vector<int>{};
        }
        for (int i = 0; i < manager.size(); ++i)
        {
            if (manager.at(i) == -1)
            {
                receivedTime[i] = 0;
                continue;
            }
            graph[manager.at(i)].push_back(i);
            receivedTime[i] = informTime.at(manager.at(i));
        }

        queue<int> q;

        q.push(headID);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int sub : graph[curr])
            {
                receivedTime[sub] = receivedTime[curr] + informTime[curr];
                q.push(sub);
            }
        }

        // res will be the maximum that each leaf node needs to receive news
        int res = 0;
        for (const auto &pair : graph)
        {
            if (pair.second.size() == 0)
            {
                res = max(res, receivedTime[pair.first]);
            }
        }
        return res;
    }
};