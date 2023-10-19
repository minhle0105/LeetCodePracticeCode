#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> graph;
        vector<int> degrees(n, 0);
        for (const auto &relation : relations)
        {
            graph[relation.front() - 1].push_back(relation.back() - 1);
            ++degrees.at(relation.back() - 1);
        }

        queue<int> q;
        unordered_map<int, int> semester;

        for (int i = 0; i < degrees.size(); ++i)
        {
            if (degrees.at(i) == 0)
            {
                q.push(i);
                semester[i] = 1;
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int course : graph[curr])
            {
                --degrees.at(course);
                if (degrees.at(course) == 0)
                {
                    semester[course] = semester[curr] + 1;
                    q.push(course);
                }
            }
        }

        if (semester.size() != n)
        {
            return -1;
        }
        int res = -1;
        for (const auto &pair : semester)
        {
            res = max(res, pair.second);
        }
        return res;
    }
};

