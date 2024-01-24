class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int itemTaken = 0;
        int sum = 0;
        while (itemTaken < k)
        {
            int count = 0;
            while (itemTaken < k && count < numOnes)
            {
                ++sum;
                ++itemTaken;
                ++count;
            }
            count = 0;
            while (itemTaken < k && count < numZeros)
            {
                ++itemTaken;
                ++count;
            }
            count = 0;
            while (itemTaken < k && count < numNegOnes)
            {
                --sum;
                ++itemTaken;
                ++count;
            }
        }
        return sum;
    }
};
