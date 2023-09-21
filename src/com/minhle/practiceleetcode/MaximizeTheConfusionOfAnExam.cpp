#include <string>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey, k, 'T'), helper(answerKey, k, 'F'));
    }

    int helper(const string &answerKey, int k, char c)
    {
        int res = 0;
        int first = 0;
        int second = 0;
        int n = 0;
        while (first < answerKey.size())
        {
            n += answerKey.at(first) == c ? 1 : 0;
            ++first;
            while (second < answerKey.size() && n > k)
            {
                n -= answerKey.at(second) == c ? 1 : 0;
                ++second;
            }
            res = max(res, first - second);
        }
        return res;
    }
};