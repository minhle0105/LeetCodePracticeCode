class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        priority_queue<double, vector<double>, greater<double>> averages;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;

        while (i < j)
        {
            averages.push((double)(nums[i] + nums[j]) / 2);
            ++i;
            --j;
        }
        return averages.top();
    }
};
