#include "AllNecessaryHeaders.h"

class Solution {
public:
    string simplifyPath(string path) {
        auto directories = split_by_slash(path);
        stack<string> simplified;
        for (const auto &directory : directories)
        {
            if (directory == "..")
            {
                if (!simplified.empty())
                {
                    simplified.pop();
                }
            }
            else
            {
                simplified.push(directory);
            }
        }
        stack<string> remaining_directories;
        while (!simplified.empty())
        {
            remaining_directories.push(simplified.top());
            simplified.pop();
        }
        string res{"/"};
        while (!remaining_directories.empty())
        {
            res += remaining_directories.top();
            res += "/";
            remaining_directories.pop();
        }
        if (res.back() == '/' && res.size() > 1)
        {
            res.pop_back();
        }
        return res;
    }
private:
    vector<string> split_by_slash(const string &path)
    {
        vector<string> directories;
        int left = 0;
        while (left < path.size())
        {
            while (left < path.size() && path[left] == '/')
            {
                ++left;
            }
            int right = left + 1;
            string directory{path[left]};
            while (right < path.size() && path[right] != '/')
            {
                directory += path[right];
                ++right;
            }
            if (directory != "." && directory[0] != '\0')
            {
                directories.push_back(directory);
            }
            left = right + 1;
        }
        return directories;
    }
};
