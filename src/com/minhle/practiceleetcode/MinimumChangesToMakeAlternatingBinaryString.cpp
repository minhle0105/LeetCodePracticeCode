class Solution {
public:
    int minOperations(string s) {
        string final_string_case_1{"0"};
        string final_string_case_2{"1"};
        int desired_size = s.size();
        build_final_string(final_string_case_1, desired_size);
        build_final_string(final_string_case_2, desired_size);

        return min(get_diff(s, final_string_case_1), get_diff(s, final_string_case_2));
    }

    void build_final_string(string &final_string, int desired_size)
    {
        while (final_string.size() < desired_size)
        {
            final_string += final_string.back() == '1' ? '0' : '1';
        }
    }

    int get_diff(const string &s, const string &final_string)
    {
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != final_string[i])
            {
                ++res;
            }
        }
        return res;
    }
};

