#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 2, 0);
        for (const auto &booking : bookings)
        {
            int start = booking.at(0);
            int end = booking.at(1);
            int amount = booking.at(2);
            diff.at(start) += amount;
            diff.at(end + 1) -= amount;
        }
        for (int i = 0; i < n; ++i)
        {
            diff.at(i + 1) = diff.at(i + 1) + diff.at(i);
        }
        diff.erase(diff.begin());
        diff.pop_back();
        return diff;
    }
};
