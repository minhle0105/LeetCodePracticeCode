#include "AllNecessaryHeaders.h"

class Solution
{
public:
    int numSquares(int n) {
        unordered_map<int, int> shortest_path;
        queue<int> q;

        shortest_path[0] = 0;
        q.push(0);

        while (!q.empty())
        {
            int current_node = q.front();
            q.pop();
            int num = 1;
            int next_node = current_node + (num * num);
            while (next_node <= n)
            {
                if (next_node == n)
                {
                    return shortest_path[current_node] + 1;
                }
                if (shortest_path.find(next_node) == shortest_path.end())
                {
                    shortest_path[next_node] = shortest_path[current_node] + 1;
                    q.push(next_node);
                }
                ++num;
                next_node = current_node + (num * num);
            }
        }
        return -1;
    }
};
