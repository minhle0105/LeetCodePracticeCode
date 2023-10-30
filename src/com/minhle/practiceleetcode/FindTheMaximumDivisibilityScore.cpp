#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int max_score = 0;
        vector<int> scores;
        scores.reserve(divisors.size());
        for (int divisor : divisors)
        {
            int score = 0;
            for (int num : nums)
            {
                if (num % divisor == 0)
                {
                    ++score;
                }
            }
            max_score = max(score, max_score);
            scores.push_back(score);
        }
        vector<int> qualified_divisors;
        for (size_t i = 0; i < divisors.size(); ++i)
        {
            if (scores.at(i) == max_score)
            {
                qualified_divisors.push_back(divisors.at(i));
            }
        }
        std::sort(qualified_divisors.begin(), qualified_divisors.end());
        return qualified_divisors.at(0);
    }
};

