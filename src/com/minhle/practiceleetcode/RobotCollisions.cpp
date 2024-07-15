class Solution {
public:
    struct Robot
    {
        int index;
        int position;
        int health;
        char direction;

        Robot (int index, int position, int health, char direction) : index(index), position(position), health(health), direction(direction)
        {

        };
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Robot> robots;
        for (int i = 0; i < positions.size(); ++i)
        {
            Robot robot{i, positions[i], healths[i], directions[i]};
            robots.push_back(robot);
        }

        sort(robots.begin(), robots.end(), [](const Robot &r1, const Robot &r2){
            return r1.position < r2.position;
        });
        stack<Robot> st;
        for (const Robot &robot : robots)
        {
            if ((st.empty()) || (robot.direction == st.top().direction || robot.direction == 'R'))
            {
                st.push(robot);
            }
            else
            {
                auto curr = robot;
                bool push_curr = true;
                while (!st.empty() && curr.direction != st.top().direction)
                {
                    auto top = st.top();
                    st.pop();
                    if (top.health == curr.health)
                    {
                        push_curr = false;
                        break;
                    }
                    if (top.health < curr.health)
                    {
                        --curr.health;
                    }
                    else
                    {
                        --top.health;
                        st.push(top);
                        push_curr = false;
                        break;
                    }
                }
                if (push_curr)
                {
                    st.push(curr);
                }
            }
        }
        robots.clear();
        while (!st.empty())
        {
            robots.push_back(st.top());
            st.pop();
        }
        sort(robots.begin(), robots.end(), [](const Robot &r1, const Robot &r2){
            return r1.index < r2.index;
        });
        vector<int> res;
        for (const Robot &robot : robots)
        {
            res.push_back(robot.health);
        }
        return res;

    }
};
