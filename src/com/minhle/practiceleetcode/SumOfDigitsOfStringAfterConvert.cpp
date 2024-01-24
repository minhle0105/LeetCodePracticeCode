#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        map<char, int> map;
        int ind = 1;
        for (int i = 97; i < 97 + 26; ++i)
        {
            map[(char) i] = ind;
            ++ind;
        }
        string converted_s;
        for (char c : s)
        {
            int val = map[c];
            converted_s += to_string(val);
        }
        int res = calculate(num, k, 0);
        return res;
    }
    int calculate(string num, int k, int count)
    {
        if (count == k)
        {
            return num;
        }
        int sum = 0;
        
        return calculate(sum, k, count + 1);
    }
};

