#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int minLength = to_string(low).size();
        int maxLength = to_string(high).size();

        vector<int> res;
        string num;
        for (int length = minLength; length <= maxLength; ++length)
        {
            for (int start = 1; start <= 10 - length; ++start)
            {
                num += to_string(start);
                while (num.size() < length)
                {
                    num += to_string((num.back() - '0') + 1);
                }
                if (low <= stoi(num) && stoi(num) <= high)
                {
                    res.push_back(stoi(num));
                }
                num.clear();
            }
        }
        return res;
    }
};

