class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        int left = 1;
        int right = pow(10, 5);
        while (left < right - 1)
        {
            long long mid = (left + right) / 2;
            if (nApples(mid) >= neededApples)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return 8 * (nApples(left) >= neededApples ? left : right);
    }

    long long nApples(long long half_edge)
    {
        long long i = 0;
        long long value = 1;
        long long sum = 0;
        long long n = half_edge * 2 + 1;

        while (i <= half_edge)
        {
            sum += (i * value);
            if (i != n - i - 1)
            {
                sum += ((n - i - 1) * value);
            }
            ++i;
            ++value;
        }
        return (sum - ((0 + half_edge) * (half_edge + 1)) / 2) * 4;
    }
};
