struct Comparator
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < n; ++i)
        {
            graph[i] = vector<pair<int, int>>{};
        }
        
        for (const auto &edge : edges)
        {
            int src = edge[0];
            int dst = edge[1];
            int weight = edge[2];

            graph[src].push_back({weight, dst});
            graph[dst].push_back({weight, src});
        }        

        auto shortest_distances = dijkstra(graph, 0, disappear);

        vector<int> res(n, -1);
        for (const auto &pair : shortest_distances)
        {
            int node = pair.first;
            int time = pair.second;
            res[node] = time;
        }
        return res;
    }
    unordered_map<int, int> dijkstra(unordered_map<int, vector<pair<int, int>>> &graph, int src, const vector<int> &disappear)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> min_heap;
        min_heap.push({0, src});
        unordered_map<int, int> shortest_distances;
        while (!min_heap.empty())
        {
            auto top = min_heap.top();
            min_heap.pop();
            int w1 = top.first;
            int n1 = top.second;

            if (shortest_distances.find(n1) != shortest_distances.end())
            {
                continue;
            }
            if (w1 >= disappear[n1])
            {
                continue;
            }
            shortest_distances[n1] = w1;
            for (const auto &neighbor : graph[n1])
            {
                int w2 = neighbor.first;
                int n2 = neighbor.second;

                if (shortest_distances.find(n2) != shortest_distances.end())
                {
                    continue;
                }
                min_heap.push({w1 + w2, n2});
            }
        }
        return shortest_distances;
    }
};
