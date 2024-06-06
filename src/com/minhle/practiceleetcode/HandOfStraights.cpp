class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> counter;
        for (int h : hand)
        {
            ++counter[h];
        }
        while (!counter.empty())
        {
            int next = counter.begin()->first;
            --counter[next];
            if (counter[next] == 0)
            {
                counter.erase(next);
            }
            vector<int> group = {next};

            while (group.size() < groupSize)
            {
                int target = group.back() + 1;
                if (counter.find(target) == counter.end())
                {
                    return false;
                }
                group.push_back(target);
                --counter[target];
                if (counter[target] == 0)
                {
                    counter.erase(target);
                }
            }
        }
        return true;
    }
};