#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty())
        {
            st.push({val, val});
            return;
        }
        int next_min = min(val, st.top().second);
        st.push({val, next_min});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
