class Solution {
public:
// patterns: row n has row n - 1 as prefix
// at row n, each position in second half is the flip of the symmetric position in the first half
    int kthGrammar(int n, int k) {
        if (n == 1)
        {
            return 0;
        }
        if (n == 2)
        {
            return k == 1 ? 0 : 1;
        }
        int half_length = pow(2, n - 1) / 2;
        if (k > half_length)
        {
            return 1 - kthGrammar(n - 1, k - half_length);
        }
        return kthGrammar(n - 1, k);
    }
};
