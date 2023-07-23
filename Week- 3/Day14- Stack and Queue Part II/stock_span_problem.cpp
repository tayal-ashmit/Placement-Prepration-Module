class StockSpanner {
  public:
    vector<int> arr;

    StockSpanner() { }
    
    int next(int price) {
        int i, count=0;
        arr.push_back(price);
        i= arr.size()-1;
        while(i>=0) {
            if(arr[i] <= price) {
                count++;
                i--;
            }
            else
                break;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */