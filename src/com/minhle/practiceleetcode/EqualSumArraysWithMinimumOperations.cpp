#include "AllNecessaryHeaders.h"

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = get_sum(nums1);
        int sum2 = get_sum(nums2);
        if (sum1 == sum2)
        {
            return 0;
        }
        if (sum1 > sum2)
        {
            return minOperations(nums1, nums2, sum1, sum2);
        }
        return minOperations(nums2, nums1, sum2, sum1);
    }
private:
    int get_sum(const vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        return sum;
    }

    int minOperations(const vector<int> &larger_array, const vector<int> &smaller_array, int larger_sum, int smaller_sum)
    {
        int sum_diff = abs(larger_sum - smaller_sum);
        vector<int> larger_gains;
        vector<int> smaller_gains;
        larger_gains.reserve(larger_array.size());
        smaller_gains.reserve(smaller_array.size());

        for (int num : larger_array)
        {
            larger_gains.push_back(num - 1);
        }
        for (int num : smaller_array)
        {
            smaller_gains.push_back(6 - num);
        }
        vector<int> gains;
        gains.reserve(larger_gains.size() + smaller_gains.size());
        for (const int gain : larger_gains)
        {
            gains.push_back(gain);
        }
        for (const int gain : smaller_gains)
        {
            gains.push_back(gain);
        }
        sort(gains.begin(), gains.end(), [](const int a, const int b){
            return a > b;
        });
        int count = 0;
        int accumulated_gain = sum_diff;

        for (const int gain : gains)
        {
            accumulated_gain -= gain;
            ++count;
            if (accumulated_gain <= 0)
            {
                return count;
            }
        }
        return -1;
    }
};
