class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 1;
        long right = num;
        while (left < right - 1)
        {
            long mid = left + ((right - left) / 2);
            if (mid * mid == num)
            {
                return true;
            }
            if (mid * mid > num)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        return left * left == num || right * right == num;
    }
};
