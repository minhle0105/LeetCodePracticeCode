#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int i = 0;
        while (i < nums.size() && nums.at(i) < target)
        {
            ++i;
        }
        while (i < nums.size() && nums.at(i) == target)
        {
            res.push_back(i);
            ++i;
        }
        return res;
    }
};
