#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int first_pointer = 0;
        while (first_pointer < s.length())
        {
            int second_pointer = first_pointer;
            while (second_pointer < s.length() && s.at(second_pointer) == s.at(first_pointer))
            {
                ++second_pointer;
            }
            groups.push_back(second_pointer - first_pointer);
            first_pointer = second_pointer;
        }
        int res = 0;
        for (size_t i = 0; i < groups.size() - 1; ++i)
        {
            res += min_(groups.at(i), groups.at(i + 1));
        }
        return res;
    }

    int min_(int a, int b)
    {
        return a < b ? a : b;
    }
};
