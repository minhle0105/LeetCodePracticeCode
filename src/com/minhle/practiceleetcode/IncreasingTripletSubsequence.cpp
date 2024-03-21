class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;
        for (int num : nums)
        {
            if (num < a)
            {
                a = num;
            }
            else if (num < b && num > a)
            {
                b = num;
            }
            else if (num > b && num > a)
            {
                return true;
            }
        }
        return false;
    }
};
