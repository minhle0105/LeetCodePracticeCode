#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i)
        {
            int num = arr.at(i);
            int find_double = binary_search(arr, 2 * num);
            if (find_double != -1 && find_double != i)
            {
                return true;
            }
        }
        return false;
    }

    int binary_search(const vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums.at(mid) == target)
            {
                return mid;
            }
            if (nums.at(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};
