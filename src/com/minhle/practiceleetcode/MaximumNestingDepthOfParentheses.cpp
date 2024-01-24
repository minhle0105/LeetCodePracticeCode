#include "AllNecessaryHeaders.h"                                    

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        stack<char> st;
        for (char c : s)
        {
            if (c == '(')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                st.pop();
            }
            res = max(res, static_cast<int>(st.size()));
        }
        return res;
    }
};
