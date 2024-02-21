class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int top = nums.back();
        return top * k + ((k * (k - 1)) / 2);
    }
};
