#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        // because I'm planning on initalizing window size at 1, which means second = 0 and first = 1
        // so if arr.size() == 1 the window is never initialized (out of bound)
        // --> this is an edge case to be handled separately.
        if (arr.size() == 1)
        {
            return 1;
        }
        int res = 0;
        int first = 1;
        int second = 0;
        while (first < arr.size())
        {
            // handle case of arr with two elements, [9,9] or [9,8]
            if (first == arr.size() - 1)
            {
                res = arr.at(first) != arr.at(first - 1) ? max(res, 2) : max(res, 1);
            }
            while ((first < arr.size() - 1) &&
                    (arr.at(first) > arr.at(first - 1) && arr.at(first) > arr.at(first + 1) ||
                    arr.at(first) < arr.at(first - 1) && arr.at(first) < arr.at(first + 1)))
            {
                ++first;
                res = max(first - second + 1, res);
            }
            second = first;
            ++first;

        }
        return res;
    }
};
