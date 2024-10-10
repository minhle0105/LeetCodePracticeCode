class Solution {
public:
    int myAtoi(string s) {
        int pos = 0;
        while (pos < s.size() && s[pos] == ' ')
        {
            ++pos;
        };
        string input;
        if (s[pos] == '-' || s[pos] == '+')
        {
            for (int i = pos + 1; i < s.size(); ++i)
            {
                if (!isdigit(s[i]))
                {
                    break;
                }
                input += s[i];
            }
            int res = conversion(input);
            if (res == -1)
            {
                return s[pos] == '-' ? pow(-2, 31) : pow(2, 31) - 1;
            }
            return s[pos] == '-' ? -1 * res : res;
        }
        for (int i = pos; i < s.size(); ++i)
        {
            if (!isdigit(s[i]))
            {
                break;
            }
            input += s[i];
        }
        int res = conversion(input);
        return res == -1 ? pow(2, 31) - 1 : res;
    }

    int conversion(const string &s)
    {
        long long res = 0;
        int pow_ = s.size() - 1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!isdigit(s[i]))
            {
                break;
            }
            if ((s[i] - '0') * pow(10, pow_) > LONG_LONG_MAX)
            {
                return -1;
            }
            res += (s[i] - '0') * pow(10, pow_);
            if (res > INT_MAX)
            {
                return -1;
            }
            --pow_;
        }
        return res;
    }
};
