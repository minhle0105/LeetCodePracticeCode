#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int first_pointer = 0;
        int second_pointer = 0;
       	unordered_map<char, int> counter;
        while (first_pointer < s.size())
        {
            if (counter.find(s.at(first_pointer)) == counter.end())
            {
                counter[s.at(first_pointer)] = 0;
            }
            ++counter[s.at(first_pointer)];
            ++first_pointer;
            while (second_pointer < s.size() && counter.size() == 3)
            {
                res += s.size() - first_pointer + 1;
                --counter[s.at(second_pointer)];
                if (counter[s.at(second_pointer)] == 0)
                {
                    counter.erase(counter.find(s.at(second_pointer)));
                }
                ++second_pointer;
            }
        }
        return res;
    }
};
