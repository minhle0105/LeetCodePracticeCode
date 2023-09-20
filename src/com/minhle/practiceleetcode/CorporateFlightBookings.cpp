#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        for (const auto &booking : bookings)
        {
            for (int i = booking.at(0); i <= booking.at(1); ++i)
            {
                res.at(i - 1) += booking.at(2);
            }
        }
        return res;
    }
};
