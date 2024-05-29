class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, vector<string>> graph;
        unordered_set<string> all_regions;
        for (const auto &region : regions)
        {
            auto src = region[0];
            all_regions.insert(src);
            for (int i = 1; i < region.size(); ++i)
            {
                graph[src].push_back(region[i]);
                all_regions.insert(region[i]);
            }
        }
        auto src = find_src(graph, all_regions);

        unordered_map<string, string> path = bfs(graph, src);


        vector<string> path_1 = trace_back(path, region1);
        vector<string> path_2 = trace_back(path, region2);

        unordered_set<string> s1(path_1.begin(), path_1.end());
        unordered_set<string> s2(path_2.begin(), path_2.end());

        return path_1.size() < path_2.size() ? find_lowest_common_ancestor(path_1, s2) : find_lowest_common_ancestor(path_2, s1);
    }

    string find_lowest_common_ancestor(const vector<string> &path, const unordered_set<string> &s)
    {
        for (const auto &p : path)
        {
            if (s.find(p) != s.end())
            {
                return p;
            }
        }
        return "";
    }

    vector<string> trace_back(unordered_map<string, string> &path, const string &src)
    {
        vector<string> trace_path;

        auto curr_1 = src;
        while (curr_1 != "-1")
        {
            trace_path.push_back(curr_1);
            curr_1 = path[curr_1];
        }

        return trace_path;
    }

    string find_src(unordered_map<string, vector<string>> &graph, unordered_set<string> &all_regions)
    {
        for (const auto &pair : graph)
        {
            for (const auto &r : pair.second)
            {
                all_regions.erase(r);
            }
        }
        string src;
        for (const auto &r : all_regions)
        {
            src = r;
            break;
        }
        return src;
    }

    unordered_map<string, string> bfs(unordered_map<string, vector<string>> &graph, const string &src)
    {
        queue<string> q;
        unordered_set<string> visited;
        unordered_map<string, string> path;

        q.push(src);
        visited.insert(src);
        path[src] = "-1";

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (const auto &child : graph[curr])
            {
                if (visited.find(child) == visited.end())
                {
                    q.push(child);
                    visited.insert(child);
                    path[child] = curr;
                }
            }
        }
        return path;
    }
};
