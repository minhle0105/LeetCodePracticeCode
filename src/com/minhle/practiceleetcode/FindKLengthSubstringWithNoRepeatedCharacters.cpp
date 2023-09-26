#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (s.size() < k)
        {
            return 0;
        }
        unordered_map<char, int> counter;
        int res = 0;
        for (int i = 0; i < k; ++i)
        {
            if (counter.find(s.at(i)) == counter.end())
            {
                counter[s.at(i)] = 0;
            }
            ++counter[s.at(i)];
        }
        if (counter.size() == k)
        {
            ++res;
        }
        for (int i = 1; i + k <= s.size(); ++i)
        {
            char new_c = s.at(i + k - 1);
            if (counter.find(new_c) == counter.end())
            {
                counter[new_c] = 0;
            }
            ++counter[new_c];
            --counter[s.at(i - 1)];
            if (counter[s.at(i - 1)] == 0)
            {
                counter.erase(counter.find(s.at(i - 1)));
            }
            if (counter.size() == k)
            {
                ++res;
            }
        }
        return res;
    }
};