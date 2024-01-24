#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;


class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
        {
            return 0;
        }
        vector<bool> visited(routes.size(), false);
        unordered_set<int> routes_containing_target;

        queue<pair<int, int>> q;

        for (int i = 0; i < routes.size(); ++i)
        {
            sort(routes[i].begin(), routes[i].end());
            bool this_route_has_source = contains(routes[i], source);
            bool this_route_has_target = contains(routes[i], target);
            if (this_route_has_source && this_route_has_target)
            {
                return 1;
            }
            if (this_route_has_source)
            {
                visited[i] = true;
                q.emplace(i, 1);
            }
            if (this_route_has_target)
            {
                routes_containing_target.insert(i);
            }
        }

        unordered_map<int, vector<int>> graph;
        construct_graph(routes, graph);

        return bfs(graph, visited, routes_containing_target, q);
    }

private:

    void construct_graph(const vector<vector<int>> &routes, unordered_map<int, vector<int>> &graph)
    {
        for (int i = 0; i < routes.size() - 1; ++i)
        {
            auto current_route = routes[i];
            for (int j = i + 1; j < routes.size(); ++j)
            {
                auto next_route = routes[j];
                bool intersect = two_routes_intersect(current_route, next_route);
                if (intersect)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }

    int bfs(unordered_map<int, vector<int>> &graph, vector<bool> &visited, const unordered_set<int> &routes_containing_target, queue<pair<int, int>> &q)
    {
        while (!q.empty())
        {
            auto curr = q.front().first;
            auto level = q.front().second;
            q.pop();

            for (int next : graph[curr])
            {
                if (!visited[next])
                {
                    q.emplace(next, level + 1);
                    visited[next] = true;
                    if (routes_containing_target.find(next) != routes_containing_target.end())
                    {
                        return level + 1;
                    }
                }
            }
        }
        return -1;
    }

    bool two_routes_intersect(const vector<int> &route1, const vector<int> &route2)
    {
        int first = 0;
        int second = 0;
        while (first < route1.size() && second < route2.size())
        {
            if (route1[first] == route2[second])
            {
                return true;
            }
            if (route1[first] < route2[second])
            {
                ++first;
            }
            else
            {
                ++second;
            }
        }
        return false;
    }

    bool contains(const vector<int> &route, int stop)
    {
        int left = 0;
        int right = route.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (route[mid] == stop)
            {
                return true;
            }
            if (route[mid] < stop)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return route[left] == stop || route[right] == stop;
    }
};

