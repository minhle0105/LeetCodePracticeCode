class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char c : s)
        {
            if (st.empty())
            {
                st.push(c);
            }
            else
            {
                if ( (islower(c) && toupper(c) == st.top()) || 
                     (isupper(c) && tolower(c) == st.top()) )
                {
                    st.pop();
                }
                else
                {
                    st.push(c);
                }
            }
        }
        string res(st.size(), ' ');
        int i = res.size() - 1;
        while (!st.empty())
        {
            res[i] = st.top();
            st.pop();
            --i;
        }
        return res;
    }
};
