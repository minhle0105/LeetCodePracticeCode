#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        if (k <= 1)
        {
            return 0;
        }
        int first = 0;
        int second = 0;
        int current = 1;
        while (first < nums.size())
        {
            current *= nums.at(first);
            while (second < nums.size() && current >= k)
            {
                current /= nums.at(second);
                ++second;
            }
            ++first;
            res += (first - second );
        }
        return res;
    }
};