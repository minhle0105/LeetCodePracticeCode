class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_set<int> people;
        people.insert(0);
        people.insert(firstPerson);
        map<int, vector<pair<int, int>>> meetings_by_time;
        for (const auto &meeting : meetings)
        {
            int p1 = meeting[0];
            int p2 = meeting[1];
            int time = meeting[2];
            meetings_by_time[time].emplace_back(p1, p2);
        }
        for (const auto &meeting : meetings_by_time)
        {
            auto all_people_at_this_time = meeting.second;
            unordered_map<int, vector<int>> graph;
            vector<int> people_who_already_knew;

            for (const auto &name : all_people_at_this_time)
            {
                graph[name.first].push_back(name.second);
                graph[name.second].push_back(name.first);
                if (people.find(name.first) != people.end())
                {
                    people_who_already_knew.push_back(name.first);
                }
                if (people.find(name.second) != people.end())
                {
                    people_who_already_knew.push_back(name.second);
                }
            }

            unordered_set<int> knew;

            for (int person : people_who_already_knew)
            {
                if (knew.find(person) == knew.end())
                {
                    dfs(graph, person, knew);
                }
            }

            for (int person : knew)
            {
                people.insert(person);
            }
        }
        vector<int> res(people.begin(), people.end());
        return res;
    }

    void dfs(unordered_map<int, vector<int>> &graph, int source, unordered_set<int> &knew)
    {
        knew.insert(source);
        for (int neighbor : graph[source])
        {
            if (knew.find(neighbor) == knew.end())
            {
                dfs(graph, neighbor, knew);
            }
        }
    }
};

