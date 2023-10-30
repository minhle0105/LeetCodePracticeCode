#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix.front().front();
        int right = matrix.back().back();

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            int countLessThanOrEqualsToMid = countNLessThanOrEqualsTo(matrix, mid);
            if (countLessThanOrEqualsToMid < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return countNLessThanOrEqualsTo(matrix, left) < k ? right : left;
    }

    int countNLessThanOrEqualsTo(const vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int res = 0;
        int left = 0;
        int right = n - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (matrix.at(mid).front() > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        for (int i = 0; i <= right; ++i)
        {
            res += countNLessThanOrEqualsTo(matrix.at(i), target);
        }
        return res;
    }

    int countNLessThanOrEqualsTo(const vector<int> &nums, int target)
    {
        if (target < nums.front())
        {
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums.at(mid) <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (nums.at(right) <= target)
        {
            return right + 1;
        }
        return left + 1;
    }
};