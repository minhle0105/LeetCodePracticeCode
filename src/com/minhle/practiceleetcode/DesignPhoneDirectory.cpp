#include <unordered_set>

using namespace std;

class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i)
        {
            unoccupied.insert(i);
        }
    }

    int get() {
        int res = -1;
        if (unoccupied.size() == 0)
        {
            return res;
        }
        for (int num : unoccupied)
        {
            res = num;
            break;
        }
        unoccupied.erase(res);
        occupied.insert(res);
        return res;
    }

    bool check(int number) {
        return occupied.find(number) == occupied.end();
    }

    void release(int number) {
        if (occupied.find(number) != occupied.end())
        {
            occupied.erase(number);
            unoccupied.insert(number);
        }
    }
private:
    unordered_set<int> occupied;
    unordered_set<int> unoccupied;
};