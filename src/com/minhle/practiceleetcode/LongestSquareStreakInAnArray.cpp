class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        const int MAXIMUM_VALUE = sqrt(pow(10, 5));
        for (int num : nums)
        {
            int curr = num;
            int count = 0;
            while (binary_search(nums, curr))
            {
                ++count;
                if (count == 5)
                {
                    // because when we start with even the smallest number possible, which is 2
                    // 2 * 2 = 4
                    // 4 * 4 = 16
                    // 16 * 16 = 256
                    // 256 * 256 = 65536
                    // 65536 * 65536 already exceeds 10^5, which is the maximum possible value for any element in num
                    break;
                }
                if (curr > MAXIMUM_VALUE)
                {
                    // because at this point, for sure curr * curr won't be in the array
                    break;
                }
                curr *= curr;
            }
            if (count > 1)
            {
                res = max(res, count);
            }
        }
        return res == 0 ? -1 : res;
    }
private:
    int binary_search(const vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return nums[left] == target || nums[right] == target;
    }
};
