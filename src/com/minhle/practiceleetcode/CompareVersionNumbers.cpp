class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = split(version1);
        auto v2 = split(version2);
        while (v1.size() < v2.size())
        {
            v1.push_back(0);
        }
        while (v1.size() > v2.size())
        {
            v2.push_back(0);
        }
        int i = 0;
        int j = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] == v2[i])
            {
                ++i;
                ++j;
                continue;
            }
            else if (v1[i] < v2[i])
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }

        return 0;
    }

    vector<int> split(const string &version)
    {
        string curr;
        vector<int> res;
        int i = 0;
        while (i < version.size())
        {
            if (version[i] == '.')
            {
                res.push_back(stoi(curr));
                curr.clear();
            }
            else
            {
                curr += version[i];
            }
            ++i;
        }
        res.push_back(stoi(curr));
        return res;
    }
};
