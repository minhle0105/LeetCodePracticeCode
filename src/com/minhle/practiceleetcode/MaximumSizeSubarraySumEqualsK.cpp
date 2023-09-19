#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        vector<int> prefix_sum;
        prefix_sum.reserve(nums.size() + 1);
        prefix_sum.push_back(0);
        map<int, vector<int>> prefix_sum_pos;
        for (int i = 0; i < nums.size(); ++i)
        {
            prefix_sum.push_back(prefix_sum.back() + nums.at(i));
            if (prefix_sum_pos.find(prefix_sum.back()) == prefix_sum_pos.end())
            {
                prefix_sum_pos[prefix_sum.back()] = vector<int>{};
            }
            prefix_sum_pos[prefix_sum.back()].push_back(i + 1);
        }
        int res = 0;
        for (int i = 0; i < prefix_sum.size(); ++i)
        {
            int plus_k = prefix_sum.at(i) + k;
            if (prefix_sum_pos.find(plus_k) != prefix_sum_pos.end())
            {
                res = max(res, prefix_sum_pos[plus_k].back() - i);
            }
        }
        return res;
    }
};
