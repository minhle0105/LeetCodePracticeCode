#include <string>

using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = int_to_string(num);
        string::size_type sz;
        int res = 0;
        for (int i = 0; i + k <= s.size(); ++i)
        {
            string sub = s.substr(i, k);
            int sub_int = stoi(sub, &sz);
            if (sub_int != 0 && num % sub_int == 0)
            {
                ++res;
            }
        }
        return res;
    }
    string int_to_string(int num)
    {
        string res;
        while (num != 0)
        {
            res += to_string(num % 10);
            num /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
