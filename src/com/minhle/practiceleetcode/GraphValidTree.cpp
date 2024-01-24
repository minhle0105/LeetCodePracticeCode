#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> graph;
        for (int i = 0; i < n; ++i)
        {
            graph[i] = vector<int>{};
        }  
        for (const auto &edge : edges)
        {
            int a = edge.front();
            int b = edge.back();
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        return dfs(graph, 0, n);
    }

    bool dfs(map<int, vector<int>> &graph, int source, int n)
    {
        set<int> visited;
        stack<int> st;
        set<int> st_set;
        st.push(source);
        st_set.insert(source);
        visited.insert(source);
        
        while (!st.empty())
        {
            int curr = st.top();
            st_set.erase(curr);
            st.pop();

            for (int neighbor : graph[curr])
            {
                if (visited.find(neighbor) != visited.end())
                {
                    if (st_set.find(neighbor) != st_set.end())
                    {
                        return false;
                    }
                    continue;
                }
                visited.insert(neighbor);
                st.push(neighbor);
                st_set.insert(neighbor);
            }
        }
        return visited.size() == n;
    }
};
