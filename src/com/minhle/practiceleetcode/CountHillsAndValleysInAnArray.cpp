class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;

        for (int i = 1; i < nums.size() - 1;)
        {
            int left_closet_non_equal_neighbor = find_closet_neighbor(nums, i, -1);
            int right_closet_non_equal_neighbor = find_closet_neighbor(nums, i, 1);
            if (left_closet_non_equal_neighbor == -1 || right_closet_non_equal_neighbor == -1)
            {
                ++i;
                continue;
            }
            if ((nums[left_closet_non_equal_neighbor] < nums[i] && nums[right_closet_non_equal_neighbor] < nums[i]) ||
                (nums[left_closet_non_equal_neighbor] > nums[i] && nums[right_closet_non_equal_neighbor] > nums[i]))
            {
                i = right_closet_non_equal_neighbor;
                ++res;
            }
            else
            {
                ++i;
            }
        }
        return res;
    }
private:
    int find_closet_neighbor(const vector<int> &nums, int pos, int direction)
    {
        if (direction == -1)
        {
            for (int i = pos - 1; i >= 0; --i)
            {
                if (nums[i] != nums[pos])
                {
                    return i;
                }
            }
        }
        if (direction == 1)
        {
            for (int i = pos + 1; i < nums.size(); ++i)
            {
                if (nums[i] != nums[pos])
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
