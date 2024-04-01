class Solution {
public:
    // basically my idea is to perform dfs on each connected component to find its diameter

    // diameter is found by performing dfs to find furthest node from a random node, and then performing dfs again
    // to find the furthest node from the furthest node found from first dfs

    // two nodes are connected if they don't represent the same character.
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> graph(parent.size(), vector<int>{});
        for (int i = 1; i < parent.size(); ++i)
        {
            if (s[i] == s[parent[i]])
            {
                continue;
            }
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }

        vector<bool> visited(parent.size(), false);
        const int n = parent.size();
        int res = 1;
        for (int i = 0; i < parent.size(); ++i)
        {
            if (!visited[i])
            {
                res = max(res, find_diameter(graph, i, visited, n));
            }
        }
        return res;
    }
private:
    int find_diameter(const vector<vector<int>> &graph, int src, vector<bool> &visited, const int n)
    {
        unordered_map<int, int> levels;
        levels[src] = 1;
        int diameter = 1;

        dfs(graph, src, levels[src], visited, levels, diameter);
        int max_level_here = 0;
        for (const auto &pair : levels)
        {
            max_level_here = max(max_level_here, pair.second);
        }    

        for (const auto &pair : levels)
        {
            if (pair.second == max_level_here)
            {
                vector<bool> visited_temp(n, false);
                levels[pair.first] = 1;
                dfs(graph, pair.first, levels[pair.first], visited_temp, levels, diameter);
                break;
            }
        }
        return diameter;
    }

    void dfs(const vector<vector<int>> &graph, int src, int prev_level, vector<bool> &visited, unordered_map<int, int> &levels, int &max_level)
    {
        visited[src] = true;
        max_level = max(max_level, levels[src]);
        for (int neighbor : graph[src])
        {
            if (!visited[neighbor])
            {
                levels[neighbor] = prev_level + 1;
                dfs(graph, neighbor, levels[neighbor], visited, levels, max_level);
            }
        }
    }
};
