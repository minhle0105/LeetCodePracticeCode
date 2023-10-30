#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitudes(gain.size() + 1, 0);
        for (int i = 0; i < gain.size(); ++i)
        {
            altitudes.at(i + 1) = altitudes.at(i) + gain.at(i);
        }
        int res = altitudes.at(0);
        for (int altitude : altitudes)
        {
            res = max(res, altitude);
        }
        return res;
    }
};
