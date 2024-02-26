class Solution {
public:
    int countGoodNumbers(long long n) {
        const int MOD = pow(10, 9) + 7;
        long long nOdds = n / 2;
        long long nEvens = (n / 2) + (n % 2);
        long long res = modPow(5, nEvens, MOD);
        res *= modPow(4, nOdds, MOD);
        return res % MOD;
    }

    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) 
        {
            if (exp & 1)
            {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result % mod;
    }
};
