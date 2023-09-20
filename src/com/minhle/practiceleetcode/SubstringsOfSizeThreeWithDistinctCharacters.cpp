#include <string>

using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int res = 0;
        for (int i = 0; i + 3 <= s.size(); ++i)
        {
            set<char> set_;
            int curr = i;
            
            while (curr < i + 3)
            {
                set_.insert(s.at(curr));
                ++curr;
            }
            if (set_.size() == 3)
            {
                ++res;
            }
        }
        return res;
    }
};
