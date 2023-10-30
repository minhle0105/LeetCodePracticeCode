#include <string>
#include <vector>
#include <set>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, vector<string>> graph;
        map<string, string> email_to_account;
        for (const auto &account : accounts)
        {
            if (account.size() == 2)
            {
                graph[account.at(1)] = vector<string>{};
                email_to_account[account.back()] = account.front();
                continue;
            }
            for (int i = 1; i < account.size() - 1; ++i)
            {
                for (int j = i + 1; j < account.size(); ++j)
                {
                    if (graph.find(account.at(i)) == graph.end())
                    {
                        graph[account.at(i)] = vector<string>{};
                    }
                    if (graph.find(account.at(j)) == graph.end())
                    {
                        graph[account.at(j)] = vector<string>{};
                    }
                    graph[account.at(i)].push_back(account.at(j));
                    graph[account.at(j)].push_back(account.at(i));
                    email_to_account[account.at(i)] = account.front();
                    email_to_account[account.at(j)] = account.front();
                }
            }
        }
        set<string> visited;
        vector<vector<string>> totalRes;
        for (const auto &pair : graph)
        {
            auto source = pair.first;
            if (visited.find(source) != visited.end())
            {
                continue;
            }
            dfs(graph, email_to_account, visited, pair.first, totalRes);
        }
        return totalRes;
    }

    void dfs(map<string, vector<string>> &graph, map<string, string> &email_to_account, set<string> &visited, const string &source, vector<vector<string>> &totalRes)
    {
        stack<string> st;
        vector<string> res;
        res.push_back(email_to_account[source]);
        st.push(source);
        visited.insert(source);
        res.push_back(source);
        while (!st.empty())
        {
            auto curr = st.top();
            st.pop();
            for (const auto &neighbor : graph[curr])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    visited.insert(neighbor);
                    st.push(neighbor);
                    res.push_back(neighbor);
                }
            }
        }
        sort(res.begin() + 1, res.end());
        totalRes.push_back(res);
    }
};