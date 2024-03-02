class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (nums[left] >= k)
        {
            return left;
        }
        if (nums[right] >= k)
        {
            return right;
        }
        return k;
    }
};
