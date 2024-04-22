class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
       unordered_set<int> restricted_nodes(restricted.begin(), restricted.end());
       unordered_map<int, vector<int>> graph;
        if (restricted_nodes.find(0) != restricted_nodes.end())
        {
            return 0;
        }
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        dfs(graph, 0, restricted_nodes, visited);

        return visited.size();
    }

    void dfs(unordered_map<int, vector<int>> &graph, int curr, const unordered_set<int> &restricted_nodes, 
             unordered_set<int> &visited)
    {
        if (visited.find(curr) != visited.end() || restricted_nodes.find(curr) != restricted_nodes.end())
        {
            return;
        }
        visited.insert(curr);
        for (int neighbor : graph[curr])
        {
            dfs(graph, neighbor, restricted_nodes, visited);
        }
    }
};
