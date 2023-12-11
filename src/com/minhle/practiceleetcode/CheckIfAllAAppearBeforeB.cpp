#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool checkString(string s) {
        int last_a_index = -1;
        int first_b_index = -1;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == 'a')
            {
                last_a_index = i;
                break;
            }
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'b')
            {
                first_b_index = i;
                break;
            }
        }
        if (last_a_index == -1 || first_b_index == -1)
        {
            return true;
        }
        return last_a_index < first_b_index;
    }
};