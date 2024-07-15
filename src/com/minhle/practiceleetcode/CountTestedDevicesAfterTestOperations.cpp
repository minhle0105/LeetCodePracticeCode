class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int res = 0;
        for (int i = 0; i < batteryPercentages.size(); ++i)
        {
            if (batteryPercentages[i] > res)
            {
                ++res;
            }
        }
        return res;
    }
};
