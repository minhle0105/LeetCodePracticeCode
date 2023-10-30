#include <vector>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0;
        int first_pointer = 0;
        while (first_pointer < nums.size())
        {
            int current = nums.at(first_pointer);
            if (current % 2 != 0 || current > threshold)
            {
                ++first_pointer;
                continue;
            }

            int second_pointer = first_pointer + 1;

            while ((second_pointer < nums.size()) && ((nums.at(second_pointer) % 2) != (nums.at(second_pointer - 1) % 2)) && (nums.at(second_pointer) <= threshold)) 
            {
                ++second_pointer;
            }
            res = max(res, second_pointer - first_pointer);
            first_pointer = second_pointer;
        }
        return res;
    }
};
