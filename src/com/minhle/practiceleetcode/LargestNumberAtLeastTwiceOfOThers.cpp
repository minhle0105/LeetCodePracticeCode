class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest_element = nums[0];
        int index = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > largest_element)
            {
                largest_element = nums[i];
                index = i;
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == index)
            {
                continue;
            }
            if (nums[i] * 2 > largest_element)
            {
                return -1;
            }
        }
        return index;
    }
};
