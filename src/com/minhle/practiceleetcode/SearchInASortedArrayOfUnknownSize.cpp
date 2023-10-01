#include <vector>

using namespace std;


class ArrayReader {
    public:
        virtual int get(int index) = 0;
 };

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0;
        int right = INT_MAX;
        const long OUT_OF_BOUND = static_cast<long>(pow(2, 31)) - 1;
        while (left < right - 1)
        {
            int mid = left + ((right - left) / 2);
            int key = reader.get(mid);
            if (key == OUT_OF_BOUND)
            {
                right = mid - 1;
            }
            else if (key == target)
            {
                return mid;
            }
            else if (key < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (reader.get(left) == target)
        {
            return left;
        }
        if (reader.get(right) == target)
        {
            return right;
        }
        return -1;
    }
};