#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        const int max_size_nums = 1000;
        vector<int> visited(max_size_nums + 1, -1);
        queue<int> q;
        q.push(start);
        visited.at(start) = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int num : nums)
            {
                vector<int> next = {curr + num, curr - num, curr ^ num};
                for (int n : next)
                {
                    if (n == goal)
                    {
                        return visited.at(curr) + 1;
                    }
                    if (0 <= n && n <= 1000 && visited.at(n) == -1)
                    {
                        visited.at(n) = visited.at(curr) + 1;
                        q.push(n);
                    }
                }
            }
        }

        return -1;
    }
};
