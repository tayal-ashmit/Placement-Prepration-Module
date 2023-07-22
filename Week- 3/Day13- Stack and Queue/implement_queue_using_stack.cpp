class MyQueue {
public:
    vector<int> v;

    MyQueue() { }
    
    void push(int x) {
        v.push_back(x);
    }
    
    int pop() {
        int k= v.front();
        v.erase(v.begin());
        return k;
    }
    
    int peek() {
        return v.front();
    }
    
    bool empty() {
        if(v.size()==0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */