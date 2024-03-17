class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int asteroid : asteroids)
        {
            bool flag = true;
            while (!res.empty() && (res.back() > 0 && asteroid < 0))
            {
                if (abs(res.back()) < abs(asteroid))
                {
                    res.pop_back();
                    continue;
                }
                if (abs(res.back()) == abs(asteroid))
                {
                    res.pop_back();
                }
                flag = false;
                break;
            }
            if (flag)
            {
                res.push_back(asteroid);
            }
        }
        return res;
    }
};
