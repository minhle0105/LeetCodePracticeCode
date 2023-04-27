#include <vector>
#include <queue>

using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i)
        {
            check_existed[i] = 1;
            min_heap.push(i);
        }
    }
    
    int popSmallest() {
        if (min_heap.empty())
        {
            return 0;
        }
        int val = min_heap.top();
        min_heap.pop();
        check_existed[val] = 0;
        return val;
    }
    
    void addBack(int num) {
        if (check_existed[num] == 1)
        {
            return;
        }
        min_heap.push(num);
        check_existed[num] = 1;
    }
private:
    int check_existed[1001];
    priority_queue<int, vector<int>, greater<int>> min_heap;
};

