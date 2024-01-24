import java.util.*;

class Job implements Comparable<Job>
{
    int difficulty;
    int profit;

    public Job(int d, int p)
    {
        this.difficulty = d;
        this.profit = p;
    }

    @Override
    public int compareTo(Job o)
    {
        return Integer.compare(this.difficulty, o.difficulty);
    }
}

class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        List<Job> jobs = new ArrayList<>();
        for (int i = 0; i < difficulty.length; ++i)
        {
            jobs.add(new Job(difficulty[i], profit[i]));
        }
        Collections.sort(jobs);
        int[] prefix_max = new int[profit.length];
        prefix_max[0] = jobs.get(0).profit;
        for (int i = 1; i < profit.length; ++i)
        {
            prefix_max[i] = Math.max(prefix_max[i - 1], jobs.get(i).profit);
        }
        int res = 0;
        for (int a : worker)
        {
            int ind = binary_search(jobs, a);
            if (ind == -1)
            {
                res += 0;
            }
            else
            {
                res += prefix_max[ind];
            }
        }
        return res;
    }

    private int binary_search(List<Job> jobs, int target)
    {
        int left = 0;
        int right = jobs.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (jobs.get(mid).difficulty <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (jobs.get(right).difficulty <= target)
        {
            return right;
        }
        if (jobs.get(left).difficulty <= target)
        {
            return left;
        }
        return -1;
    }
}