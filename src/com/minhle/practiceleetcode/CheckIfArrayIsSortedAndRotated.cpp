class Solution {
public:
    bool check(vector<int>& nums) {
        int pivot = -1;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                pivot = i + 1;
                break;
            }
        }

        if (pivot == -1)
        {
            return true;
        }
        vector<int> rotated;
        for (int i = pivot; i < nums.size(); ++i)
        {
            rotated.push_back(nums[i]);
        }
        for (int i = 0; i < pivot; ++i)
        {
            rotated.push_back(nums[i]);
        }
        for (int i = 0; i < rotated.size() - 1; ++i)
        {
            if (rotated[i] > rotated[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};
