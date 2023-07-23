vector<int> prevSmaller(vector<int> &arr) {
    int n= arr.size();
    stack<int> st;
    vector<int> vec;

    for(int i=0; i<n; i++) {
        while(!st.empty() && arr[i]<=st.top()) {
            st.pop();
        }

        if(st.empty()) {
            vec.push_back(-1);
        }
        else {
            vec.push_back(st.top());
        }

       st.push(arr[i]);
    }

    return vec;
}
