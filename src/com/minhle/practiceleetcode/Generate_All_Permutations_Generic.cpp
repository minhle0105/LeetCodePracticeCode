#include <vector>
#include <unordered_map>

using namespace std;

class Permutation
{
public:
    template<typename T>
    vector<vector<T>> generate_all_permutations(const vector<T> &inputs)
    {
        unordered_map<T, int> counter;
        for (int input : inputs)
        {
            ++counter[input];
        }
        vector<vector<T>> all_perms;
        vector<T> current_perm;
        backtracking(current_perm, inputs, all_perms, counter);
        return all_perms;
    }

    template<typename T>
    void backtracking(vector<T> &current_perm, const vector<T> &inputs,
                      vector<vector<T>> &all_perms, unordered_map<T, int> &counter)
    {
        if (current_perm.size() == inputs.size())
        {
            all_perms.push_back(current_perm);
            return;
        }

        for (int input : inputs)
        {
            if (counter[input] > 0)
            {
                --counter[input];
                current_perm.push_back(input);
                backtracking(current_perm, inputs, all_perms, counter);
                current_perm.pop_back();
                ++counter[input];
            }
        }
    }
};