class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        int current_min = INT_MAX;
        for (int num : nums)
        {
            if (num <= current_min)
            {
                current_min = num;
            }
            else
            {
                res = max(res, num - current_min);
            }
        }
        return res;
    }
};
