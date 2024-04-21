class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int> &log1, const vector<int> &log2){
            return log1[1] < log2[1];
        });
        
        vector<pair<int, int>> query_pairs;
        query_pairs.reserve(queries.size());

        for (int i = 0; i < queries.size(); ++i)
        {
            query_pairs.push_back({i, queries[i]});
        }

        sort(query_pairs.begin(), query_pairs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
            return p1.second < p2.second;
        });

        vector<int> res(queries.size(), n);
        res.reserve(queries.size());
        unordered_map<int, int> occupied_servers;
        int count = 0;
        int left = 0;
        int right = 0;

        for (const auto &query : query_pairs)
        {
            int i = query.first;
            int start_time = query.second - x;
            int end_time = query.second;

            while (right < logs.size() && logs[right][1] <= end_time)
            {
                if (occupied_servers.find(logs[right][0]) == occupied_servers.end())
                {
                    ++count;
                }
                ++occupied_servers[logs[right][0]];   
                ++right;
            }

            while (left < logs.size() && logs[left][1] < start_time)
            {
                --occupied_servers[logs[left][0]];
                if (occupied_servers[logs[left][0]] == 0)
                {
                    occupied_servers.erase(logs[left][0]);
                    --count;
                }
                ++left;
            }
            res[i] = n - count;
        }
        return res;
    }
};
