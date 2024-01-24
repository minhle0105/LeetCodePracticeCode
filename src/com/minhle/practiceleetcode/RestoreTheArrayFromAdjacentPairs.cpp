#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> degrees;
        for (const auto &pair : adjacentPairs)
        {
            graph[pair.front()].push_back(pair.back());
            graph[pair.back()].push_back(pair.front());
            ++degrees[pair.back()];
            ++degrees[pair.front()];
        }
        stack<int> st;
        unordered_set<int> visited;

        for (const auto &pair : degrees)
        {
            if (pair.second == 1)
            {
                st.push(pair.first);
                visited.insert(pair.first);
            }
        }

        vector<int> res;

        while (!st.empty())
        {
            int curr = st.top();
            st.pop();

            res.push_back(curr);

            for (int neighbor : graph[curr])
            {
                --degrees[neighbor];
                if (degrees[neighbor] == 1 && visited.find(neighbor) == visited.end())
                {
                    st.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return res;
    }
};
