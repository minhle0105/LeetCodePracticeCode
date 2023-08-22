#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        map<int, char> char_map;
        construct_char_map(char_map);
        string res{""};
        convertToTitle(columnNumber, res, char_map);
        reverse(res);
        return res;
    }

    void construct_char_map(map<int, char> &char_map)
    {
        for (int i = 0; i < 26; ++i)
        {
            char_map[i] = i + 65;
        }
    }

    void convertToTitle(int column_number, string &current, map<int, char> &char_map)
    {
        if (column_number <= 0)
        {
            return;
        }
        column_number--;
        current += char_map[column_number % 26];
        column_number /= 26;
        convertToTitle(column_number, current, char_map);
    }

    void reverse(string &s)
    {
        for (int i = 0; i < s.size() / 2; ++i)
        {
            char temp = s.at(i);
            s.at(i) = s.at(s.size() - i - 1);
            s.at(s.size() - i - 1) = temp;
        }
    }
};
