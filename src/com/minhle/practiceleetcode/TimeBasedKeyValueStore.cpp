class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (storage.find(key) == storage.end())
        {
            return "";
        }
        if (storage[key][0].first > timestamp)
        {
            return "";
        }
        if (timestamp > storage[key].back().first)
        {
            return storage[key].back().second;
        }
        return binary_search(key, timestamp);
    }

private:
    unordered_map<string, vector<pair<int, string>>> storage;

    string binary_search(const string &key, int timestamp)
    {
        int left = 0;
        int right = storage[key].size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (storage[key][mid].first == timestamp)
            {
                return storage[key][mid].second;
            }
            if (storage[key][mid].first < timestamp)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (storage[key][right].first <= timestamp)
        {
            return storage[key][right].second;
        }
        if (storage[key][left].first <= timestamp)
        {
            return storage[key][left].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
