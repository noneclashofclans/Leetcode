class CustomStack {
public:
    int maxSize;
    stack<int> st;
    CustomStack(int maxSize) {
        this-> maxSize = maxSize;
    }
    
    void push(int x) {
        // check for overflow condition
        // if overflow, then return, else push
        int currentSize = st.size();
        if (currentSize < maxSize){
            st.push(x);
        }   
    }
    
    int pop() {
        // check for underflow condition
        // if underflow, then don't pop, else pop
            if (st.empty()) return -1;
       
            int poppedVal = st.top();
            st.pop(); 
            return poppedVal;
    }
    
    void increment(int k, int val) {
        // icrement the bottom k elements by val
        stack<int> sn;
        int n = st.size();
        int count = 0;
        while (!st.empty()){
            sn.push(st.top());
            st.pop();

        }
        while (!sn.empty()){
            int tp = sn.top();
            sn.pop();
            if (count < k) tp += val;
            st.push(tp);
            count++;
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