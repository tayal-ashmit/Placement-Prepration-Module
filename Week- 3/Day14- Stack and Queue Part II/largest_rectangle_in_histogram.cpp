class Solution {
  public:
    vector<int>NextSmallest(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> v(n);
        st.push(-1);

        for(int i=n-1; i>=0; i--) {
            int curr= heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }

            v[i]= st.top();
            st.push(i);
        }
        return v;
    }

    vector<int>PrevSmallest(vector<int>& heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=0; i<n; i++) {   
            int curr= heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }

            ans[i]= st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();

        vector<int> next(n);
        next= NextSmallest(heights, n);

        vector<int> prev(n);
        prev= PrevSmallest(heights, n);

        int MaxArea= INT_MIN;
        for(int i=0; i<n; i++) {
            int l= heights[i];
            if(next[i] == -1) {
                next[i]= n;
            }
            
            int b= next[i]-prev[i]-1;
            int NewArea= l*b;
            MaxArea= max(MaxArea, NewArea);
        }
        return MaxArea;
    }
};