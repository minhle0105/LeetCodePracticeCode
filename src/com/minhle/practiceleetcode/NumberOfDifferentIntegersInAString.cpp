class Solution {
public:
    int numDifferentIntegers(string word) {
        int res = 0;
        int i = 0;
        unordered_set<string> nums;
        while (i < word.size())
        {
            while (i < word.size() && !isdigit(word[i]))
            {
                ++i;
            }
            int j = i;
            while (j < word.size() && isdigit(word[j]))
            {
                ++j;
            }
            auto num = trim_leading_zeros(word.substr(i, j - i));
            if (!num.empty())
            {
                nums.insert(num);
            }
            i = j;
        }
        return nums.size();
    }

    string trim_leading_zeros(const string &num)
    {
        string res;
        int i = 0;
        int count_0 = 0;
        while (i < num.size() && num[i] == '0')
        {
            ++count_0;
            ++i;
        }
        if (count_0 == num.size() && count_0 > 0)
        {
            return "0";
        }
        while (i < num.size() && isdigit(num[i]))
        {
            res += num[i];
            ++i;
        }
        return res;
    }
};
