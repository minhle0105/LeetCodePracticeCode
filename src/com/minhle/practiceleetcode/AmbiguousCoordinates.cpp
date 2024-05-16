class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<pair<string, string>> all_pairs;
        int n = s.size();
        for (int i = 2; i < n - 1; ++i) 
        {
            auto first_half = s.substr(1, i - 1);
            auto second_half = s.substr(i, n - 1 - i);
            all_pairs.push_back({first_half, second_half});
        }

        vector<string> res;
        for (const auto &pair : all_pairs) 
        {
            auto first = pair.first;
            auto second = pair.second;
            vector<string> all_first = placing_decimal_split(first);
            vector<string> all_second = placing_decimal_split(second);
            for (const auto &f : all_first) 
            {
                for (const auto &s : all_second) 
                {
                    res.push_back("(" + f + ", " + s + ")");
                }
            }
        }
        return res;
    }
private:
    vector<string> placing_decimal_split(const string &number) 
    {
        vector<string> res;
        int n = number.size();
        if (isValidNumber(number)) 
        {
            res.push_back(number);
        }
        for (int i = 1; i < n; ++i) 
        {
            string integer_part = number.substr(0, i);
            string fractional_part = number.substr(i);
            if (isValidNumber(integer_part) && isValidFraction(fractional_part)) 
            {
                res.push_back(integer_part + "." + fractional_part);
            }
        }
        return res;
    }

    bool isValidNumber(const string &s) 
    {
        return s == "0" || (s[0] != '0' && !s.empty());
    }

    bool isValidFraction(const string &s) 
    {
        return !s.empty() && s.back() != '0';
    }
};

