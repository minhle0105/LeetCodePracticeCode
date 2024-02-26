#include "AllNecessaryHeaders.h"

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int GREATEST_ASCII_CODE_IN_RANGE = 122;
        const int SMALLEST_ASCII_CODE_IN_RANGE = 97;
        vector<int> ascii(s.begin(), s.end());
        vector<int> count(s.size() + 1, 0);
        for (int i = 1; i < s.size(); ++i)
        {
            count[i] = s[i] - s[i - 1];
        }
        for (const auto &shift : shifts)
        {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 1 ? 1 : -1;

            count[start] += direction;
            count[end + 1] -= direction;
        }
        string res;
        for (int i = 0; i < ascii.size(); ++i)
        {
            if (i == 0)
            {
                ascii[i] += count[0];
            }
            else
            {
                ascii[i] = ascii[i - 1] + count[i];
            }
            while (ascii[i] > GREATEST_ASCII_CODE_IN_RANGE)
            {
                ascii[i] = (SMALLEST_ASCII_CODE_IN_RANGE - 1) + (ascii[i] - GREATEST_ASCII_CODE_IN_RANGE);
            }
            while (ascii[i] < SMALLEST_ASCII_CODE_IN_RANGE)
            {
                ascii[i] = (GREATEST_ASCII_CODE_IN_RANGE + 1) - (SMALLEST_ASCII_CODE_IN_RANGE - ascii[i]);
            }
            res += static_cast<char>(ascii[i]);
        }
        return res;
    }
};
