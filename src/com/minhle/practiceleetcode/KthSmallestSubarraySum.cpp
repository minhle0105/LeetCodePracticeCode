#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        int min_num = 1;
        int total_sum = 0;
        for (int num : nums)
        {
            min_num = min(min_num, num);
            total_sum += num;
        }
        int left = min_num;
        int right = total_sum;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            int count = countNumberOfSubarrayWithSumLessThanOrEqualsTo(nums, mid);
            if (count < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        int count_left = countNumberOfSubarrayWithSumLessThanOrEqualsTo(nums, left);
        if (count_left < k)
        {
            return right;
        }
        return left;
    }
    int countNumberOfSubarrayWithSumLessThanOrEqualsTo(const vector<int> &nums, int target)
    {
        int left = 0;
        int right = 0;
        int current = 0;
        int res = 0;
        while (right < nums.size())
        {
            current += nums.at(right);
            while (left < nums.size() && current > target)
            {
                current -= nums.at(left);
                ++left;
            }
            ++right;
            res += (right - left);
        }
        return res;
    }
};
