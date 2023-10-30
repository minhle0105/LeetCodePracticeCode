#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() <= 2)
        {
            return 0;
        }
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                int current_sum = nums.at(i) + nums.at(j);
                int count = binary_search(nums, j + 1, current_sum);
                if (count == -1)
                {
                    continue;
                }
                res += (count - j);
            }
        }
        return res;
    }

    int binary_search(const vector<int> &nums, int left, int target)
    {
        int right = nums.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums.at(mid) < target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (nums.at(right) < target)
        {
            return right;
        }
        if (nums.at(left) < target)
        {
            return left;
        }
        return -1;
    }
};