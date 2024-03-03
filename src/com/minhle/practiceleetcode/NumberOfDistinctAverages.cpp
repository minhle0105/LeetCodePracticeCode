class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double> averages;
        sort(nums.begin(), nums.end());
        int i = 0; 
        int j = nums.size() - 1;
        while (i < j)
        {
            averages.insert(static_cast<double>((nums[i] + nums[j])) / 2);
            ++i;
            --j;
        }
        return static_cast<int>(averages.size());
    }
};
