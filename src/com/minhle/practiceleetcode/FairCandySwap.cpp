#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        int sumAlice = sum(aliceSizes);
        int sumBob = sum(bobSizes);
        int c_sum = sumBob - sumAlice;
        for (int i = 0; i < aliceSizes.size(); ++i)
        {
            int x = aliceSizes.at(i);
            int y = (c_sum + 2 * x) / 2;
            int y_ind = binary_search(bobSizes, y);
            if (y_ind != -1)
            {
                return vector<int>{aliceSizes.at(i), bobSizes.at(y_ind)};
            }
        }
        return vector<int>{};
    }

    int binary_search(const vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right - 1)
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
        if (nums.at(left) == target)
        {
            return left;
        }
        return nums.at(right) == target ? right : -1;
    }

    int sum(const vector<int> &nums)
    {
        int res = 0;
        for (int num : nums)
        {
            res += num;
        }
        return res;
    }
};
