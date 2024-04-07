class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = abs(nums.back() - nums.front());

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            int count = count_distance_pairs(nums, mid);
            if (count >= k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return count_distance_pairs(nums, left) >= k ? left : right;
    }
private:
    int count_distance_pairs(const vector<int> &nums, int target)
    {
        int count = 0;
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; ++i)
        {
            int furthest = binary_search_helper(nums, nums[i], min(n - 1, i + 1), target);
            if (furthest != -1)
            {
                count += (furthest - i);
            }
        }
        return count;
    }

    int binary_search_helper(const vector<int> &nums, int nums_at_i, int left, int target)
    {
        int right = nums.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums[mid] - nums_at_i <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (nums[right] - nums_at_i <= target)
        {
            return right;
        }
        if (nums[left] - nums_at_i <= target)
        {
            return left;
        }
        return -1;
    }
};
