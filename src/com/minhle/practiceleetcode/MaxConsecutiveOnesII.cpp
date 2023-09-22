#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int first = 0;
        int second = 0;
        int nZeroes = 0;
        while (first < nums.size())
        {
            nZeroes += nums.at(first) == 0 ? 1 : 0;
            ++first;
            while (second < nums.size() && nZeroes > 1)
            {
                nZeroes -= nums.at(second) == 0 ? 1 : 0;
                ++second;
            }
            res = max(res, first - second);
        }
        return res;
    }
};
