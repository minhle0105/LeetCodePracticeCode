#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        map<int, int> map;
        for (int i = 0; i < mat.size(); ++i)
        {
            map[i] = 0;
        }
        int max_count = INT_MIN;
        for (int i = 0; i < mat.size(); ++i)
        {
            int count = 0;
            for (int j = 0; j < mat.at(i).size(); ++j)
            {
                if (mat.at(i).at(j) == 1)
                {
                    ++count;
                }
            }
            max_count = max(count, max_count);
            map[i] = count;
        }
        vector<int> res;
        for (int i = 0; i < mat.size(); ++i)
        {
            if (map[i] == max_count)
            {
                res.push_back(i);
                res.push_back(max_count);
                break;
            }
        }
        return res;   
    }
};

