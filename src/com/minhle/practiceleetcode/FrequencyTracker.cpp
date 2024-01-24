#include <map>

using namespace std;

class FrequencyTracker {
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        // if number does not exist yet
        if (number_count.find(number) == number_count.end())
        {
            number_count[number] = 1;
            // if frequency 1 does not exist yet
            if (freq_count.find(1) == freq_count.end())
            {
                freq_count[1] = 1;
            }
            else
            {
                ++freq_count[1];
            }
        }   
        else
        {
            // number already exists, then increment its frequency, increment count for new frequency, decrement count for old frequency
            int init_freq = number_count[number];
            number_count[number] = init_freq + 1;
            --freq_count[init_freq];
            if (freq_count.find(init_freq + 1) == freq_count.end())
            {
                freq_count[init_freq + 1] = 1;
            }
            else
            {
                ++freq_count[init_freq + 1];
            }
        }
    }

    void deleteOne(int number) {
        // if number does not exist yet, nothing happen
        if (number_count.find(number) == number_count.end())
        {
            return;
        }
        // if number exists, decrement its frequency by 1.
        int init_freq = number_count[number];
        --number_count[number];
        // if frequency is now 0, we remove the number from tracker
        if (number_count[number] == 0)
        {
            number_count.erase(number);
        }
        // decrement old frequency by 1
        --freq_count[init_freq];
        // increment new frequency by 1
        if (freq_count.find(init_freq - 1) == freq_count.end() && init_freq != 0)
        {
            freq_count[init_freq - 1] = 1;
        }
        else
        {
            ++freq_count[init_freq - 1];
        }
    }

    bool hasFrequency(int frequency) {
        // if frequency map contains frequency, and it must be greater than 0.
        return freq_count.find(frequency) == freq_count.end() ? false : freq_count[frequency] > 0;
    }
private:
    map<int, int> number_count;
    map<int, int> freq_count;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
