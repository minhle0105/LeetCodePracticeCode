class Solution {
public:
    set<pair<int, int>> belongs_to_path;
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        // find shortest_path --> dijkstra
        // use backtracking to find all path with desired distance
        unordered_map<int, vector<pair<int, int>>> graph;

        for (const auto &edge : edges)
        {
            int a = edge[0];
            int b = edge[1];
            int weight = edge[2];

            graph[a].emplace_back(weight, b);
            graph[b].emplace_back(weight, a);
        }

        int shortest_distance = dijkstra(graph, n - 1);
        vector<pair<int, int>> current_path;
        set<int> visited;
        visited.insert(0);
        backtracking(graph, current_path, 0, 0, n - 1, shortest_distance, visited);

        vector<bool> res;
        res.reserve(edges.size());
        for (const auto &edge : edges)
        {
            pair<int, int> key = {min(edge[0], edge[1]), max(edge[0], edge[1])};
            res.push_back(belongs_to_path.find(key) != belongs_to_path.end());
        }
        return res;
    }

    void backtracking(unordered_map<int, vector<pair<int, int>>> &graph, vector<pair<int, int>> &current_path,
                      int current_node, int current_weight, const int dst, const int shortest, set<int> &visited)
    {
        if (current_node == dst)
        {
            if (current_weight == shortest)
            {
                for (const auto &edge : current_path)
                {
                    belongs_to_path.insert({min(edge.first, edge.second), max(edge.first, edge.second)});
                }
            }
            return;
        }
        if (current_weight > shortest)
        {
            return;
        }
        for (const auto &neighbor : graph[current_node])
        {
            int weight = neighbor.first;
            int node = neighbor.second;
            if (node == 2)
            {
                int a = 0;
            }
            if (visited.find(node) != visited.end())
            {
                continue;
            }

            current_path.push_back({current_node, node});
            visited.insert(node);
            backtracking(graph, current_path, node, current_weight + weight, dst, shortest, visited);
            visited.erase(node);
            current_path.pop_back();
        }
    }

    int dijkstra(unordered_map<int, vector<pair<int, int>>> &graph, int dst)
    {
        unordered_map<int, int> shortest_distances;
        struct Comparator
        {
            bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
            {
                return p1.first > p2.first;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> edges;

        edges.emplace(0, 0);

        while (!edges.empty())
        {
            auto top = edges.top();
            edges.pop();
            int w = top.first;
            int n = top.second;

            if (shortest_distances.find(n) != shortest_distances.end())
            {
                continue;
            }

            shortest_distances[n] = w;

            for (const auto &neighbor : graph[n])
            {
                int neighbor_w = neighbor.first;
                int neighbor_n = neighbor.second;

                if (shortest_distances.find(neighbor_n) == shortest_distances.end())
                {
                    edges.emplace(w + neighbor_w, neighbor_n);
                }
            }
        }
        if (shortest_distances.find(dst) == shortest_distances.end())
        {
            return -1;
        }
        return shortest_distances[dst];
    }
};
