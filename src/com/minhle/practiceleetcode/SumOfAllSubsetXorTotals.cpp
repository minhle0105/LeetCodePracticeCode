class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        generate_subsets(nums, 0, res, 0);
        return res;
    }
private:
    void generate_subsets(const vector<int> &nums, int current_position, int &res, int sum_subset)
    {
        res += sum_subset;
        for (int i = current_position; i < nums.size(); ++i)
        {
            sum_subset ^= nums[i];
            generate_subsets(nums, i + 1, res, sum_subset);
            sum_subset = sum_subset ^ nums[i];
        }
    }
};
