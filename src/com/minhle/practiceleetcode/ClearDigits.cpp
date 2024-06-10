class Solution {
public:
    string clearDigits(string s) {
        string res;
        vector<char> st;
        for (char c : s)
        {
            if (isdigit(c))
            {
                if (!st.empty())
                {
                    st.pop_back();
                }
            }
            else
            {
                st.push_back(c);
            }
        }
        for (char c : st)
        {
            res += c;
        }
        return res;
    }
};
