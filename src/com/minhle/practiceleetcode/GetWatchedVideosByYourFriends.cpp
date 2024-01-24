#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Video {
public:
    string value;
    int frequency;

    Video(const std::string& value, int freq) : value(value), frequency(freq) {}

    bool operator<(const Video& other) const {
        if (this->frequency == other.frequency) {
            return this->value < other.value;
        }
        return this->frequency < other.frequency;
    }
};

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<int, int> levels;
        levels[id] = 0;
        queue<int> q;
        unordered_set<int> visited;
        q.push(id);
        visited.insert(id);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int neighbor : friends[curr])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    q.push(neighbor);
                    visited.insert(neighbor);
                    levels[neighbor] = levels[curr] + 1;
                }
            }
        }

        vector<Video> videos;
        unordered_map<string, int> video_frequency;
        for (const auto &pair : levels)
        {
            if (pair.second == level)
            {
                vector<string> video_names = watchedVideos.at(pair.first);
                for (const auto &name : video_names)
                {
                    ++video_frequency[name];
                }
            }
        }

        for (const auto &pair : video_frequency)
        {
            Video video{pair.first, pair.second};
            videos.push_back(video);
        }
        sort(videos.begin(), videos.end());
        vector<string> res;
        res.reserve(videos.size());
        for (const auto &video : videos)
        {
            res.push_back(video.value);
        }
        return res;
    }
};
