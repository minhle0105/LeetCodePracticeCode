#include <utility>
#include <string>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9)
        {
            return n;
        }
        pair<int, long long> prev_digits = {1, 9};
        pair<int, long long> curr_digits = {2, 189};
        int k = 3;
        while (curr_digits.second <= n)
        {
            prev_digits.first = curr_digits.first;
            prev_digits.second = curr_digits.second;
            curr_digits.first = k;
            curr_digits.second = curr_digits.second + static_cast<long long>((9 * pow(10, k - 1) * k));
            ++k;
        }
        const long nDigitsAtEndOfLeft = prev_digits.second;
        const long cLeft = pow(10, prev_digits.first);
        long left = pow(10, prev_digits.first);
        long right = get_right_limit(curr_digits.first);
        while (left < right - 1)
        {
            long mid = left + (right - left) / 2;
            long nDigitsAtEndOfMid = nDigitsAtEndOfLeft + (mid - cLeft + 1) * to_string(mid).size();
            if (nDigitsAtEndOfMid == n)
            {
                return mid % 10;
            }
            if (nDigitsAtEndOfMid < n)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        long nDigitsAtEndOfLeftNow = nDigitsAtEndOfLeft + (left - cLeft + 1) * to_string(left).size();
        long nDigitsAtEndOfRightNow = nDigitsAtEndOfLeft + ((right - cLeft) + 1) * to_string(right).size();
        if (nDigitsAtEndOfLeftNow >= n)
        {
            long diff = nDigitsAtEndOfLeftNow - n;
            if (diff == 0)
            {
                return left % 10;
            }
            string left_to_str = to_string(left);
            int pointer = left_to_str.size() - 1;
            while (diff > 0)
            {
                --pointer;
                --diff;
            }
            return left_to_str.at(pointer) - '0';
        }
        long diff = nDigitsAtEndOfRightNow - n;
        if (diff == 0)
        {
            return right % 10;
        }
        string right_to_str = to_string(right);
        int pointer = right_to_str.size() - 1;
        while (diff > 0)
        {
            --pointer;
            --diff;
        }
        return right_to_str.at(pointer) - '0';
    }

    int get_right_limit(int n)
    {
        string res;
        for (int i = 0; i < n; ++i)
        {
            res += "9";
        }
        return stoi(res);
    }
};
