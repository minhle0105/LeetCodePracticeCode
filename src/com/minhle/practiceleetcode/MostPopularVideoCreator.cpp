class Solution {
public:
    struct Video
    {
        long long views;
        string id;

        bool operator<(const Video &v)
        {
            return v.views < this->views;
        }
    };
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, vector<Video>> groups;
        unordered_map<string, long long> total_views;
        long long max_view = 0;

        long long n = creators.size();

        for (long long i = 0; i < n; ++i)
        {
            Video video;
            video.id = ids[i];
            video.views = views[i];
            groups[creators[i]].push_back(video);
            total_views[creators[i]] += video.views;
            max_view = max(max_view, total_views[creators[i]]);
        }

        for (auto &pair : groups)
        {
            sort(pair.second.begin(), pair.second.end(), [](const Video &v1, const Video &v2){
                if (v1.views == v2.views)
                {
                    return v1.id < v2.id;
                }
                return v1.views > v2.views;
            });
        }

        vector<string> popular_creators;
        for (const auto &pair : total_views)
        {
            if (pair.second == max_view)
            {
                popular_creators.push_back(pair.first);
            }
        }

        vector<vector<string>> res;
        for (const auto &creator : popular_creators)
        {
            res.push_back({creator, groups[creator][0].id});
        }
        sort(res.begin(), res.end(), [&groups](const vector<string> &p1, const vector<string> &p2){
            return p1[1] > p2[1];
        });
        return res;
    }
};
