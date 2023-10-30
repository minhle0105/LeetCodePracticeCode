#include <vector>

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for (const auto &row : grid)
        {
            res += binary_search(row);
        }
        return res;
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
