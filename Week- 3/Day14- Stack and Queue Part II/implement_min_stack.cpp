class MinStack {
public:
    vector<pair<int, int>> arr;
    int n=0;

    MinStack() {}
    
    void push(int val) {
        if(arr.empty()) {
            arr.push_back({val, val});
        }
        else {
            arr.push_back({val, min(val, arr.back().second)});
        }
        n= arr.size()-1;
    }
    
    void pop() {
        arr.erase(arr.begin()+n);
        n--;
    }
    
    int top() {
        return arr.back().first;
    }
    
    int getMin() {
        return arr.back().second;
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