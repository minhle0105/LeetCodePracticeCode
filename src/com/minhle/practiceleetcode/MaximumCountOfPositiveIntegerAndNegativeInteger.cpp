#include <vector>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        int neg = binary_search(nums);
        int pos = 0;
        for (const auto num : nums)
        {
            if (num <= 0)
            {
                break;
            }
            ++pos;
        }
        return pos > neg ? pos : neg;
    }

private:
    int binary_search(const vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums.at(mid) >= 0)
            {
                if (mid == n - 1)
                {
                    return 0;
                }
                if (nums.at(mid + 1) >= 0)
                {
                    left = mid + 1;
                }
                else
                {
                    return n - mid - 1;
                }
            }
            else
            {
                if (mid == 0)
                {
                    return n;
                }
                if (nums.at(mid - 1) >= 0)
                {
                    return n - mid;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
