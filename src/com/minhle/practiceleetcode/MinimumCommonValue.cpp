#include <vector>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums1)
        {
            if (binary_search(nums2, num) != -1)
            {
                return num;
            }
        }
        return -1;
    }
    int binary_search(const vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums.at(mid) == target)
            {
                return mid;
            }
            if (nums.at(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};
