#include <vector>

using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        vector<int> sectors(n + 1, 0);
        int max_visited_count = 0;
        for (size_t i = 0; i < rounds.size() - 1; ++i)
        {
            int src = rounds.at(i);
            int dst = rounds.at(i + 1);
            if (i == 0)
            {
                ++sectors.at(src);
            }
            int current_point = src + 1;
            while (current_point != dst + 1)
            {
                if (current_point == n + 1)
                {
                    current_point = 1;
                }
                ++sectors.at(current_point);
                max_visited_count = max_(sectors.at(current_point), max_visited_count);
                ++current_point;
            }
        }
        for (size_t i = 1; i < sectors.size(); ++i)
        {
            if (sectors.at(i) == max_visited_count)
            {
                res.push_back(i);
            }
        }
        return res;
    }

    int max_(int a, int b)
    {
        return a > b ? a : b;
    }
};
