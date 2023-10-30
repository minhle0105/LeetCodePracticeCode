#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) == 0)
            {
                nums.at(i) = -1;
            }
        }
        vector<int> prefix_sum;
        prefix_sum.push_back(nums.at(0));
        int res = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            prefix_sum.push_back(prefix_sum.back() + nums.at(i));
            if (prefix_sum.back() == 0)
            {
                res = max(res, i + 1);
            }
        }
        map<int, int> map_position;
        
        for (int i = 0; i < prefix_sum.size(); ++i)
        {
            if (map_position.find(prefix_sum.at(i)) == map_position.end())
            {
                map_position[prefix_sum.at(i)] = i;
            }
            else
            {
                res = max(res, i - map_position[prefix_sum.at(i)]);
            }
        }
        return res;
    }
};
