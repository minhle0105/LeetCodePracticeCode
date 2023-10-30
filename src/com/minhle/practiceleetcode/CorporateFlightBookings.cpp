#include <vector>

using namespace std;

class Solution {
public:
    // normal prefix sum would produce TLE with time complexity of O(N^2)
    // we use an array to keep track of the diff between nums.at(i) and nums.at(i - 1);
    // basically, with an array a[0], a[1], a[2], ... a[n], when we increase each element from 
    // a[i] to a[j] by k, with 0 <= i <= j <= n, the difference between a[i] and a[i - 1] goes up k
    // and the difference between a[j] and a[j + 1] goes down k.
    // for example, we have 1 2 3 4 5 6 7, and we want to increase 3,4,5 by 1
    // original: 1 2 3 4 5 6 7
    // after:    1 2 4 5 6 6 7
    // the difference between 2-3 was 1, now the difference from 2-4 increase by 1, which is 2
    // the difference from 5-6 was 1, now the difference from 6-6 decrease by 1, which is 0
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
