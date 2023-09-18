#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // idea is to use prefix sum to calculate number of No from 0 -> i, and number of Yes from i -> end
    // penalties[i] = n_No[i - 1] + n_Yes[i]
    int bestClosingTime(string customers) {
        vector<int> numberOfN_from_0_to_i(customers.size(), 0);
        vector<int> numberOfY_from_i_to_end(customers.size(), 0);
        numberOfN_from_0_to_i.at(0) = customers.at(0) == 'Y' ? 0 : 1;
        for (int i = 1; i < customers.size(); ++i)
        {
            if (customers.at(i) == 'Y')
            {
                numberOfN_from_0_to_i.at(i) = numberOfN_from_0_to_i.at(i - 1);
            }
            else
            {
                numberOfN_from_0_to_i.at(i) = numberOfN_from_0_to_i.at(i - 1) + 1;
            }
        }
        numberOfY_from_i_to_end.back() = customers.back() == 'Y' ? 1 : 0;
        for (int i = numberOfY_from_i_to_end.size() - 2; i >= 0; --i)
        {
            if (customers.at(i) == 'Y')
            {
                numberOfY_from_i_to_end.at(i) = numberOfY_from_i_to_end.at(i + 1) + 1;
            }
            else
            {
                numberOfY_from_i_to_end.at(i) = numberOfY_from_i_to_end.at(i + 1);
            }
        }
        vector<int> penalties(customers.size() + 1, 0);
        int min_ = INT_MAX;
        for (int i = 0; i <= customers.size(); ++i)
        {
            if (i == 0)
            {
                penalties.at(i) = numberOfY_from_i_to_end.front();
            }
            else if (i == customers.size())
            {
                penalties.at(i) = numberOfN_from_0_to_i.back();
            }
            else
            {
                penalties.at(i) = numberOfN_from_0_to_i.at(i - 1) + numberOfY_from_i_to_end.at(i);   
            }
            min_ = min(min_, penalties.at(i));
        }
        for (int i = 0; i < penalties.size(); ++i)
        {
            if (penalties.at(i) == min_)
            {
                return i;
            }
        }
        return -1;
    }
};
