class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> counter;
        for (int num : nums)
        {
            ++counter[num];
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

            while (group.size() < k)
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
