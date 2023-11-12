#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> graph;

    Graph(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; ++i)
        {
            graph[i] = vector<pair<int, int>>{};
        }

        for (const auto &edge : edges)
        {
            auto from = edge.front();
            auto to = edge.at(1);
            auto weight = edge.back();

            graph[from].push_back({weight, to});
        }
    }

    void addEdge(vector<int> edge) {
        auto from = edge.front();
        auto to = edge.at(1);
        auto weight = edge.back();

        graph[from].push_back({weight, to});
    }

    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }
private:
    int dijkstra(int node1, int node2)
    {
        auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b)
        {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);
        unordered_map<int, int> shortest_distance;

        min_heap.push({0, node1});
        while (!min_heap.empty())
        {
            auto curr = min_heap.top();
            min_heap.pop();
            auto weight = curr.first;
            auto node = curr.second;

            if (shortest_distance.find(node) != shortest_distance.end())
            {
                continue;
            }
            shortest_distance[node] = weight;

            for (auto &neighbor : graph[node])
            {
                if (shortest_distance.find(neighbor.second) != shortest_distance.end())
                {
                    if (neighbor.second == node2)
                    {
                        return shortest_distance[node2];
                    }
                    continue;
                }
                min_heap.push({neighbor.first + weight, neighbor.second});
            }
        }
        return shortest_distance.find(node2) != shortest_distance.end() ? shortest_distance[node2] : -1;
    }
};

