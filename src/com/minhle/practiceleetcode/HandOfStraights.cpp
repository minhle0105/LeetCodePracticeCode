class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_set<int> seen;
        int i = 0;
        while (i < hand.size())
        {
            vector<int> group = {hand[i]};
            seen.insert(i);
            int j = i + 1;
            while (j < hand.size() && group.size() < groupSize)
            {
                if (seen.find(j) == seen.end() && hand[j] == group.back() + 1)
                {
                    group.push_back(hand[j]);
                    seen.insert(j);
                }
                ++j;
            }
            if (group.size() != groupSize)
            {
                return false;
            }
            while (i < hand.size() && seen.find(i) != seen.end())
            {
                ++i;
            }
        }
        return true;
    }
};
