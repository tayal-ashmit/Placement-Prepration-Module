class MedianFinder {
public:
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;

    MedianFinder() {}
    
    void addNum(int num) {
        if(s.empty() || s.top()>=num)
            s.push(num);
        else
            g.push(num);

        if(s.size() > g.size()+1){
            g.push(s.top());
            s.pop();
        }

        else if(s.size() < g.size()) {
            s.push(g.top());
            g.pop();
        }
    }
    
    double findMedian() {
        if(s.size()==g.size()){
            return  s.top()/2.0 +g.top()/2.0;
        }
        return s.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */