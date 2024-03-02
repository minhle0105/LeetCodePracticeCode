class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        vector<vector<int>> res;
        while (i < firstList.size() && j < secondList.size())
        {
            if (can_merge(firstList[i], secondList[j]))
            {
                res.push_back(merge(firstList[i], secondList[j]));
            }
            if (firstList[i][1] < secondList[j][1])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return res;
    }
private:
    bool can_merge(const vector<int> &interval1, const vector<int> &interval2)
    {
        return max(interval1.front(), interval2.front()) <= min(interval1.back(), interval2.back());
    }
    
    vector<int> merge(const vector<int> &interval1, const vector<int> &interval2)
    {
        return {max(interval1.front(), interval2.front()), min(interval1.back(), interval2.back())};
    }
};
