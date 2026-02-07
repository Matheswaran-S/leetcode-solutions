class MinStack {
public:
    stack<pair<int,int>> st, mst;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,1});
            mst.push({val,1});
        }
        else{
            if(mst.top().first > val) mst.push({val,st.top().second+1});
            st.push({val,st.top().second+1});
        }
    }
    
    void pop() {
        if(st.top().second == mst.top().second) mst.pop();
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return mst.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */