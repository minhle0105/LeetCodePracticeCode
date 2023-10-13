#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        return reverseR(s, k, 0);
    }

    string reverseR(string &s, int k, int curr)
    {
        int threshold = s.size() - curr < k ? s.size() : curr + k;
        if (s.size() - curr < k)
        {
            reverse(s, curr, threshold);
            return s;
        }
        reverse(s, curr, threshold);
        if (s.size() - curr >= k && s.size() - curr < 2*k)
        {
            return s;
        }
        return reverseR(s, k, curr + 2 * k);
    }

    void reverse(string &s, int start, int end)
    {
        int mid = (start + end) / 2;
        int symmetric = end - 1;
        for (int i = start; i < mid; ++i)
        {
            char temp = s.at(i);
            s.at(i) = s.at(symmetric);
            s.at(symmetric) = temp;
            --symmetric;
        }
    }
};
