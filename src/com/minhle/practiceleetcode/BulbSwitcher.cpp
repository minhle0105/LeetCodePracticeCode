class Solution {
public:
    int bulbSwitch(int n) {
        int res = 0;
        int i = 1;
        while (i * i <= n)
        {
            ++res;
            ++i;
        }
        return res;
    }
};
