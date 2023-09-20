#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> prefix_sum;
        prefix_sum.push_back(0);
        for (int num : nums)
        {
            prefix_sum.push_back(prefix_sum.back() + num);
        }
        int sum = prefix_sum.back() - x;
        int res = -1;
        unordered_map<int, int> map_pos;
        for (int i = 0; i < prefix_sum.size(); ++i)
        {
            if (map_pos.find(prefix_sum.at(i)) == map_pos.end())
            {
                map_pos[prefix_sum.at(i)] = i;
            }
            int remaining = prefix_sum.at(i) - sum;
            if (map_pos.find(remaining) != map_pos.end())
            {
                res = max(res, i - map_pos[remaining]);
            }
        }
        return res == -1 ? res : nums.size() - res;
    }
};
