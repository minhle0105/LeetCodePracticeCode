class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n % 2 == 0)
        {
            return n;
        }
        int left = n + 1;
        int right = 2 * n;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (mid % 2 == 0 && mid % n == 0)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left % 2 == 0 && left % n == 0 ? left : right;
    }
};
