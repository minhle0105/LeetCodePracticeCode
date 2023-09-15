#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> prefix_sum(nums.size() + 1, 0);
        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            prefix_sum.at(i + 1) = prefix_sum.at(i) + nums.at(i);
        }
        map<int, int> map;
        for (int sum : prefix_sum)
        {
            if (map.find(sum) != map.end())
            {
                res += map[sum];
            }
            int sum_plus_goal = sum + goal;
            map[sum_plus_goal] = map.find(sum_plus_goal) == map.end() ? 1 : map[sum_plus_goal] + 1; 
        }
        return res;
    }
};
