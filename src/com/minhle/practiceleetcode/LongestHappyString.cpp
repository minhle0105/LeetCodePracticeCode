struct Pair {
    char c;
    int count;
    Pair(char c_, int count_) : c(c_), count(count_) {}

    bool operator<(const Pair &p2) const {
        return count < p2.count;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Pair> heap;

        heap.emplace('a', a);
        heap.emplace('b', b);
        heap.emplace('c', c);

        queue<Pair> temp;

        string res;
        while (!heap.empty())
        {
            auto top = heap.top();
            heap.pop();
            if (top.count == 0)
            {
                continue;
            }
            res += top.c;
            --top.count;
            while (!temp.empty() && temp.front().c != res.back())
            {
                heap.push(temp.front());
                temp.pop();
            }
            if (res.size() >= 2 && top.c == res[res.size() - 1] && top.c == res[res.size() - 2])
            {
                temp.push(top);
            }
            else
            {
                heap.push(top);
            }
        }

        return res;
    }
};

