class Solution {
public:
    bool checkPerfectNumber(int num) {
        int res = 0;
        for (int i = 1; i <= sqrt(num); ++i)
        {
            if (num % i == 0)
            {
                res += i;
                if (i != sqrt(num))
                {
                    res += num / i;
                }
            }
        }
        return res == num * 2;
    }
};
