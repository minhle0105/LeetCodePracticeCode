class Solution {
public:
    long long minimumSteps(string s) {
        long long nOnes = 0;
        long long res = 0;

        for (char c : s)
        {
            if (c == '1')
            {
                ++nOnes;
            }
            else
            {
                res += nOnes;
            }
        }      
        return res;
    }
};
