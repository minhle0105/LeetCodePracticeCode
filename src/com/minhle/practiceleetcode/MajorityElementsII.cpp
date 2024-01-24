#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        size_t threshold = nums.size() / 3;
        map<int, int> map;
        for (auto num : nums)
        {
            if (map.find(num) == map.end())
            {
                map[num] = 0;
            }
            map[num] = map[num] + 1;
        }
        vector<int> res;
        for (const auto &pair : map)
        {
            if (pair.second > threshold)
            {
                res.push_back(pair.first);
            }
        }
        return res;
    }
};
