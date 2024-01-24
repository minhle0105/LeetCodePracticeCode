#include <string>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        // 0 -> []
        // 1 -> char
        // 2 -> int
        for (char c : s)
        {
            if (isdigit(c))
            {
                if (st.empty() || st.top().second != 2)
                {
                    st.push({"", 2});
                }
                st.top().first += c;
            }
            else if ('a' <= c && c <= 'z')
            {
                if (st.empty() || st.top().second != 1)
                {
                    st.push({"", 1});
                }
                st.top().first += c;
            }
            else if (c == ']')
            {
                auto str = st.top().first;
                st.pop();
                auto num = stoi(st.top().first);
                st.pop();
                string new_str;
                for (int i = 0; i < num; ++i)
                {
                    new_str += str;
                }
                if (st.empty() || st.top().second != 1)
                {
                    st.push({"", 1});
                }
                st.top().first += new_str;
            }
            else
            {
                st.push({"[", 0});
            }
        }
        return st.top().first;
    }
};
