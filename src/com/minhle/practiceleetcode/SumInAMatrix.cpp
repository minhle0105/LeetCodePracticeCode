class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto &row : nums)
        {
            sort(row.begin(), row.end(), [](int a, int b){
                return a > b;
            });
        }

        int score = 0;
        int col = 0;
        const int m = nums.size();
        const int n = nums[0].size();

        while (col < n)
        {
            int row = 0;
            int max_num = nums[row][col];
            while (row < m)
            {
                max_num = max(max_num, nums[row][col]);
                ++row;
            }
            score += max_num;
            ++col;
        }

        return score;
    }
};
