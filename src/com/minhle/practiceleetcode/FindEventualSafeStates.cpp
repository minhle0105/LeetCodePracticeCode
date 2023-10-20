#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> safe(graph.size(), false);
        unordered_set<int> st;
        unordered_set<int> visited;
        for (int i = 0; i < graph.size(); ++i)
        {
            if (!safe.at(i))
            {
                safe.at(i) = !(has_cycle(graph, safe, st, visited, i));
            }
        }

        vector<int> res;
        for (int i = 0; i < safe.size(); ++i)
        {
            if (safe.at(i))
            {
                res.push_back(i);
            }
        }
        return res;
    }

private:
    bool has_cycle(const vector<vector<int>> &graph, vector<bool> &safe, unordered_set<int> &st, unordered_set<int> &visited, int current)
    {
        visited.insert(current);
        st.insert(current);
        for (int next : graph.at(current))
        {
            if (visited.find(next) == visited.end())
            {
                if (has_cycle(graph, safe, st, visited, next))
                {
                    return true;
                }
            }
            else
            {
                if (st.find(next) != st.end())
                {
                    return true;
                }
            }
        }
        st.erase(current);
        safe.at(current) = true;
        return false;
    }
};
