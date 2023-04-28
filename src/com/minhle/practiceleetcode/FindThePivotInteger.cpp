class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; ++i)
        {
            if (get_sum(1, i) == get_sum(i, n))
            {
                return i;
            }
        }
        return -1;
    }
    int get_sum(int a, int b)
    {
        return ((a + b) * (b - a + 1)) / 2;
    }
};

