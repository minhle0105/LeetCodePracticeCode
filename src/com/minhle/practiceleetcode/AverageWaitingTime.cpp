class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        double total_waiting_time = 0.0;

        int prev_end_time = 0;

        for (const auto &customer : customers)
        {
            if (prev_end_time == 0 || customer[0] >= prev_end_time)
            {
                total_waiting_time += customer[1];
                prev_end_time = (customer[0] + customer[1]);
            }
            else if (customer[0] < prev_end_time)
            {
                total_waiting_time += (prev_end_time - customer[0]) + customer[1];
                prev_end_time += customer[1];
            }
        }
        return total_waiting_time / n;
    }
};
