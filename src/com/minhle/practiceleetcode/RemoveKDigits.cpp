#include "AllNecessaryHeaders.h"

class Solution {
public:
// c - '0'
    string removeKdigits(string num, int k) {
        string res;
        int count = 0;
        stack<int> st;
        for (char c : num)
        {
            while ((!st.empty()) &&
                   ((c - '0') < st.top()) &&
                   (count < k))
                {
                    st.pop();
                    ++count;
                }
            st.push(c - '0');
        }
        while (st.size() > num.size() - k)
        {
            st.pop();
        }
        while (!st.empty())
        {
            res += to_string(st.top());
            st.pop();
        }
        while (!res.empty() && res.back() == '0')
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};
