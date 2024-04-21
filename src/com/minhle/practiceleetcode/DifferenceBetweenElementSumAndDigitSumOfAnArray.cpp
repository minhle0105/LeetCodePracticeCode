class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int element_sum = 0;
        int digit_sum = 0;

        for (int num : nums)
        {
            element_sum += num;
            digit_sum += num < 10 ? num : calculate_digit_sum(num);
        }
        return abs(element_sum - digit_sum); 
    }

    int calculate_digit_sum(int num)
    {
        int digit_sum = 0;
        while (num != 0)
        {
            digit_sum += num % 10;
            num /= 10;
        }
        return digit_sum;
    }
};
