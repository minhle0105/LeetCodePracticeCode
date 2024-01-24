#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int first = 0;
        int second = 0;
        unordered_map<int, int> counter;
        while (first < fruits.size())
        {
            if (counter.find(fruits.at(first)) == counter.end())
            {
                counter[fruits.at(first)] = 0;
            }
            ++counter[fruits.at(first)];
            ++first;
            while (second < fruits.size() && counter.size() > 2)
            {
                --counter[fruits.at(second)];
                if (counter[fruits.at(second)] == 0)
                {
                    counter.erase(counter.find(fruits.at(second)));
                }
                ++second;
            }
            res = max(res, first - second);
        }
        return res;
    }
};
