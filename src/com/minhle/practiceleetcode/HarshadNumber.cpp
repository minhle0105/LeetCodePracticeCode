class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int x_ = x;
        int digit_sum = 0;
        while (x_ != 0)
        {
            digit_sum += x_ % 10;
            x_ /= 10;
        }
        return x % digit_sum == 0 ? digit_sum : -1;
    }
};
