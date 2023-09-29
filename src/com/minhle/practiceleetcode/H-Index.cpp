#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = 0;
        for (int i = 0; i < citations.size(); ++i)
        {
            int numberOfPapersWithMoreOrEqualCitation = binary_search(citations, i, citations.at(i));
            if (numberOfPapersWithMoreOrEqualCitation <= citations.at(i))
            {
                res = max(res, numberOfPapersWithMoreOrEqualCitation);
            }
        }
        return res;
    }
    int binary_search(const vector<int> &citations, int left, int target)
    {
        int right = citations.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (citations.at(mid) >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (citations.at(left) >= target)
        {
            return citations.size() - left;
        }
        return citations.at(right) >= target ? citations.size() - right : 0;
    }
};
