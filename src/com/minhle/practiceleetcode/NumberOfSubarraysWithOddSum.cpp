#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    // basically this is based on the idea that with prefix sum, we have Sum from i to j = sum[j] - sum[i + 1].
    // a - b is odd when 1. a is odd b is even, or 2. a is even and b is odd
    // with prefix sum and dynamic programming, we keep counting at each position of prefix sum, how many odd and even numbers we are looking
    // from there to the end of the list.
    // vector<pair<int, int>> dp stores <odd, even> count
    // prefix.at(i) is odd -> dp.at(i) = {dp.at(i - 1).first - 1, dp.at(i - 1).second}
    // prefix.at(i) is even -> dp.at(i) = {dp.at(i - 1).first, dp.at(i - 1).second - 1}
    int numOfSubarrays(vector<int>& arr) {
        const int modulo = static_cast<int>((pow(10, 9) + 7));
        vector<int> prefix_sum;
        long long res = 0;
        prefix_sum.push_back(0);
        vector<pair<int, int>> dp(arr.size() + 1, pair<int, int>{});

        for (int i = 0; i < arr.size(); ++i)
        {
            prefix_sum.push_back(prefix_sum.back() + arr.at(i));
            if (prefix_sum.back() % 2 != 0)
            {
                ++dp.at(0).first;
            }
            else
            {
                ++dp.at(0).second;
            }
        }
        for (int i = 1; i < dp.size(); ++i)
        {
            dp.at(i) = prefix_sum.at(i) % 2 != 0 ? pair<int, int>{dp.at(i - 1).first - 1, dp.at(i - 1).second} : pair<int, int>{dp.at(i - 1).first, dp.at(i - 1).second - 1};
        }
        for (int i = 0; i < dp.size(); ++i)
        {
            res += prefix_sum.at(i) % 2 != 0 ? dp.at(i).second : dp.at(i).first;
        }
        return res % modulo;
    }
};
