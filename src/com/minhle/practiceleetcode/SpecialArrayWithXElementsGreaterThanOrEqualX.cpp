#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size();

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            int nGreaterThanOrEqualsToMid = countNumberGreaterThanOrEqualsTo(nums, mid);
            if (mid == nGreaterThanOrEqualsToMid)
            {
                return mid;
            }
            if (nGreaterThanOrEqualsToMid > mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (countNumberGreaterThanOrEqualsTo(nums, left) == left)
        {
            return left;
        }
        return countNumberGreaterThanOrEqualsTo(nums, right) == right ? right : -1;
    }

    int countNumberGreaterThanOrEqualsTo(const vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums.at(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (nums.at(left) >= target)
        {
            return nums.size() - left;
        }
        return nums.at(right) >= target ? nums.size() - right : 0;
    }
};
