#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int first = 0;
        int second = 0;
        int count_0 = 0;

        while (first < nums.size())
        {
            count_0 += nums.at(first) == 0 ? 1 : 0;
            ++first;
            while (second < nums.size() && count_0 > 1)
            {
                count_0 -= nums.at(second) == 0 ? 1 : 0;
                ++second;
            }
            res = max(res, first - second);
        }
        return res - 1;
    }
};
