class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int first_decreasing_position = -1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                first_decreasing_position = i;
                break;
            }
        }
        if (first_decreasing_position >= 0)
        {
            int swap_position = -1;
            for (int i = n - 1; i > first_decreasing_position; --i)
            {
                if (nums[i] > nums[first_decreasing_position])
                {
                    swap_position = i;
                    break;
                }
            }
            swap(nums[first_decreasing_position], nums[swap_position]);
        }

        int i = first_decreasing_position + 1;
        int j = n - 1;
        while (i < j)
        {
            swap(nums[i++], nums[j--]);
        }
    }
};
