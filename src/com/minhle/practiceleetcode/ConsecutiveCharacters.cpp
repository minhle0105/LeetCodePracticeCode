#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxPower(string s) {
        int power = 1;
        int left = 0;
        while (left < s.size())
        {
            int count = 1;
            int right = left + 1;
            while (right < s.size() && s[right] == s[left])
            {
                ++count;
                ++right;
            }
            power = max(power, count);
            left = right;
        }
        return power;
    }
};
