#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> map;
        vector<int> res;
        for (int i = 1; i <= 1000; ++i)
        {
            map[i] = 0;
        }
        for (vector<int> row : nums)
        {
            for (int num : row)
            {
                map[num] = map[num] + 1;
            }
        }
        for (auto pair : map)
        {
            if (pair.second == nums.size())
            {
                res.push_back(pair.first);
            }
        }
        return res;
    }
};

