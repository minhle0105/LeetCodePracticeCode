class CustomStack {
public:
    vector<int> st;
    int max_size;
    CustomStack(int maxSize) {
        max_size = maxSize;
    }
    
    void push(int x) {
        if (st.size() < max_size)
        {
            st.push_back(x);
        }
    }
    
    int pop() {
        if (st.empty())
        {
            return -1;
        }
        int res = st.back();
        st.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, (int)st.size()); ++i)
        {
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
