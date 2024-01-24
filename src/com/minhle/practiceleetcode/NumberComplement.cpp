#include "AllNecessaryHeaders.h"

class Solution {
public:
    int findComplement(int num) {
        auto binary = decimal_to_binary(num);
        flip(binary);
        return binary_to_decimal(binary);
    }
private:
    string decimal_to_binary(int num)
    {
        string binary;
        while (num != 0)
        {
            binary += to_string(num % 2);
            num /= 2;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }

    void flip(string &binary)
    {
        for (char &c : binary)
        {
            if (c == '0')
            {
                c = '1';
            }
            else
            {
                c = '0';
            }
        }
    }

    int binary_to_decimal(string &binary)
    {
        int power = 0;
        int res = 0;
        for (int i = binary.size() - 1; i >= 0; --i)
        {
            res += (binary[i] - '0') * pow(2, power);
            ++power;
        }
        return res;
    }
};
