#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums.at(mid) == target)
            {
                return mid;
            }
            // pivot is not in [left, right]
            if (nums.at(left) < nums.at(right))
            {
                if (nums.at(mid) < target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            // pivot is in [left, right]
            else
            {
                // pivot is in [mid, right]
                if (nums.at(left) < nums.at(mid))
                {
                    // [left -> mid] is strictly sorted -> perform binary search
                    if (nums.at(left) <= target && target < nums.at(mid))
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
                // pivot is in [left, mid]
                else
                {
                    // mid + 1 -> right is strictly sorted -> perform binary search
                    if (nums.at(mid) < target && target <= nums.at(right))
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
            }
        }
        if (nums.at(left) == target)
        {
            return left;
        }
        return nums.at(right) == target ? right : -1;
    }
};
