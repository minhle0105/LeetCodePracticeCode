#include "AllNecessaryHeaders.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        auto x_bin = decimal_to_binary(x);
        auto y_bin = decimal_to_binary(y);
        if (x_bin.size() < y_bin.size())
        {
            fill(x_bin, y_bin.size());
        }
        else if (x_bin.size() > y_bin.size())
        {
            fill(y_bin, x_bin.size());
        }
        return compare(x_bin, y_bin);
    }

    int compare(const string &a, const string &b)
    {
        int res = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != b[i])
            {
                ++res;
            }
        }
        return res;
    }

    void fill(string &binary, int desired_size)
    {
        string trailing_zeroes(desired_size - binary.size(), '0');
        binary = binary + trailing_zeroes;
    }

    string decimal_to_binary(int num)
    {
        string binary;
        while (num != 0)
        {
            binary += to_string(num % 2);
            num /= 2;
        }
        return binary;
    }
};
