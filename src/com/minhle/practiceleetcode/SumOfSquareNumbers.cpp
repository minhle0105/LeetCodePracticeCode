#include <limits>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c <= 1)
        {
            return true;
        }
        for (int i = 0; i <= sqrt(c); ++i)
        {
            if (i != 0 && i > c / i)
            {
                break;
            }
            if (isPerfectSquare(c - (i * i)))
            {
                return true;
            }
        }
        return false;
    }

    bool isPerfectSquare(int num)
    {
        int left = 1;
        int right = num;
        const long long max_long_long = numeric_limits<long long>::max();
        while (left < right - 1)
        {
            long long mid = left + (right - left) / 2;
            long long midSq = mid * mid;
            if (midSq == num)
            {
                return true;
            }
            if (midSq < num)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (left > (max_long_long / left))
        {
            if (right >= (max_long_long / right))
            {
                return false;
            }
            return num % right == 0 && right == num / right;
        }
        return num % left == 0 && left == num / left;
    }
};
