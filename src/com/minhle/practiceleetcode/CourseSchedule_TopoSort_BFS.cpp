#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> degrees(numCourses, 0);

        for (const auto &pair : prerequisites)
        {
            graph[pair.back()].push_back(pair.front());
            ++degrees.at(pair.front());
        }

        queue<int> q;
        vector<int> course_order;
        for (int i = 0; i < numCourses; ++i)
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
            course_order.push_back(curr);
            for (int course : graph[curr])
            {
                --degrees.at(course);
                if (degrees.at(course) == 0)
                {
                    q.push(course);
                }
            }
        }
        return course_order.size() == numCourses;
    }
};
