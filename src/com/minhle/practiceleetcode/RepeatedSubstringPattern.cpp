#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1)
        {
            return false;
        }
        set<int> factors;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s.size() % i == 0)
            {
                if (factors.find(i) != factors.end())
                {
                    break;
                }
                factors.insert(i);
                factors.insert(s.size() / i);
            }
        }
        for (int factor : factors)
        {
            if (check_all_strings_equal(truncate_string_by_size(s, factor)))
            {
                return true;
            }
        }
        return false;
    }

    vector<string> truncate_string_by_size(const string &word, int size)
    {
        vector<string> res;
        for (int i = 0; i < word.size(); i += size)
        {
            res.push_back(word.substr(i, size));
        }
        return res;
    }

    bool check_all_strings_equal(const vector<string> &strings)
    {
        if (strings.size() == 1)
        {
            return false;
        }
        set<string> set;
        for (const auto &string : strings)
        {
            set.insert(string);
        }
        return set.size() == 1;
    }
};
