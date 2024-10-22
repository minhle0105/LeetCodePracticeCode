class Solution {
public:
    char findKthBit(int n, int k) {
        string curr{"0"};
        return findKthBitRecursively(curr, n, k, 1);
    }
    char findKthBitRecursively(string &curr, int n, int k, int i)
    {
        if (i == n)
        {
            return curr[k - 1];
        }
        curr += "1";
        int pos = curr.size() - 2;
        while (pos >= 0)
        {
            curr += curr[pos--] == '0' ? '1' : '0';
        }
        return findKthBitRecursively(curr, n, k, i + 1);
    }
};
