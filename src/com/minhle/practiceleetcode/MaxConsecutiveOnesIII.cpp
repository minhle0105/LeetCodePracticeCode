#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int first_pointer = 0;
        int second_pointer = 0;
        int nZeroes = 0;
        while (first_pointer < nums.size())
        {
            nZeroes += nums.at(first_pointer) == 0 ? 1 : 0;
            ++first_pointer;
            while (second_pointer < nums.size() && nZeroes > k)
            {
                nZeroes -= nums.at(second_pointer) == 0 ? 1 : 0;
                ++second_pointer;
            }
            res = max(res, first_pointer - second_pointer);
        }
        return res;
    }
};
