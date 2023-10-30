#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        queue<int> q;
        for (int i = 0; i < graph.size(); ++i)
        {
            if (visited.at(i) == -1)
            {
                q.push(i);
                visited.at(i) = 0;

                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    for (int neighbor : graph[curr])
                    {
                        if (visited.at(neighbor) == -1)
                        {
                            visited.at(neighbor) = 1 - visited.at(curr);
                            q.push(neighbor);
                        }
                        else
                        {
                            if (visited.at(neighbor) + visited.at(curr) != 1)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
