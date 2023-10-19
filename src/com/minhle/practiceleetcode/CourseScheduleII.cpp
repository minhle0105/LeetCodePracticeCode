#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> degrees(numCourses, 0);        

        for (const auto &re : prerequisites)
        {
            graph[re.back()].push_back(re.front());
            ++degrees.at(re.front());
        }

        queue<int> q;
        for (int i = 0; i < degrees.size(); ++i)
        {
            if (degrees.at(i) == 0)
            {
                q.push(i);
            }
        }
        
        vector<int> res;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (int course : graph[curr])
            {
                --degrees.at(course);
                if (degrees.at(course) == 0)
                {
                    q.push(course);
                }
            }
        }

        return res.size() == numCourses ? res : vector<int>{};
    }
};
