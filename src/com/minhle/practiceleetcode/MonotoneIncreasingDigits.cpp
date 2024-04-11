class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string res = to_string(n);
        int length = res.size();
        int pivot = length;

        for (int i = res.size() - 1; i > 0; --i)
        {
            if (res[i] < res[i - 1])
            {
                pivot = i;
                --res[i - 1];
            }
        }

        for (int i = pivot; i < length; ++i)
        {
            res[i] = '9';
        }
        return stoi(res);
    }
};
