class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while (left < right - 1)
        {
            long mid = (left + right) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            if (mid * mid > x)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        if (right * right <= x)
        {
            return right;
        }
        return left;
    }
};
