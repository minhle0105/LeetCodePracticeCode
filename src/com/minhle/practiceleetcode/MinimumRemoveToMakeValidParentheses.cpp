class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int nOpens = 0;
        int nCloses = 0;

        for (char c : s)
        {
            if (c != '(' && c != ')')
            {
                st.push(c);
            }
            else
            {
                if (c == '(')
                {
                    st.push(c);
                    ++nOpens;
                }
                else
                {
                    if (nCloses < nOpens)
                    {
                        st.push(c);
                        ++nCloses;
                    }
                }
            }
        }

        string res;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        nOpens = 0;
        nCloses = 0;

        for (char c : res)
        {
            if (c != '(' && c != ')')
            {
                st.push(c);
            }
            else
            {
                if (c == ')')
                {
                    st.push(c);
                    ++nCloses;
                }
                else
                {
                    if (nOpens < nCloses)
                    {
                        st.push(c);
                        ++nOpens;
                    }
                }
            }   
        }
        res.clear();
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        return res;
    }
};
