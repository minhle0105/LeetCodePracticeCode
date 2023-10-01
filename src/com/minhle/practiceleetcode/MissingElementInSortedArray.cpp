#include <vector>

using namespace std;

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            int nMissingAtMid = findNMissingAtNum(nums.at(mid), nums.front(), mid);
            if (nMissingAtMid < k)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        int nMissingAtRight = findNMissingAtNum(nums.at(right), nums.front(), right);
        if (nMissingAtRight < k)
        {
            return nums.at(right) + (k - nMissingAtRight);
        }
        return nums.at(left) + (k - findNMissingAtNum(nums.at(left), nums.front(), left));
    }

    int findNMissingAtNum(int num, const int beginning, int i)
    {
        return num - beginning - i;
    }
};
