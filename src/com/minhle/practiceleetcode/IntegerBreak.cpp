#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2)
        {
            return 1;
        }
        map<int, int> dp;
        return recursive(dp, n);
    }

    int recursive(map<int, int> &dp, int n)
    {
        if (n <= 2)
        {
            return n;
        }
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            int a = i * (n - i);
            int b = dp.find(n - i) != dp.end() ? i * dp[n - i] : i * recursive(dp, n - i);
            res = max(res, max(a, b));
        }
        dp[n] = res;
        return res;
    }
};
