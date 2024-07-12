class Solution {
public:
    int maximumGain(string s, int x, int y) {
        return x < y ? process(s, x, y, 'b', 'a') : process(s, y, x, 'a', 'b');
    }

    int process(string &s, int smaller_point, int greater_point, char first_char, char second_char)
    {
        int score = 0;
        stack<char> st;
        for (char c : s)
        {
            if (c == second_char)
            {
                if (st.empty() || st.top() != first_char)
                {
                    st.push(c);
                }
                else if (st.top() == first_char)
                {
                    st.pop();
                    score += greater_point;
                }
            }
            else
            {
                st.push(c);
            }
        }
        s.clear();
        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());

        for (char c : s)
        {
            if (c == first_char)
            {
                if (st.empty() || st.top() != second_char)
                {
                    st.push(c);
                }
                else if (st.top() == second_char)
                {
                    st.pop();
                    score += smaller_point;
                }
            }
            else
            {
                st.push(c);
            }
        }
        return score;
    }
};
