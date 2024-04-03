class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = nums.front();

        for (int num : nums)
        {
            right = max(num, right);
        }

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (get_sum(nums, mid) <= threshold)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return get_sum(nums, left) <= threshold ? left : right;
    }
private:
    int get_sum(const vector<int> &nums, int divisor)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += (ceil((1.0 * num) / divisor));
        }
        return sum;
    }
};
