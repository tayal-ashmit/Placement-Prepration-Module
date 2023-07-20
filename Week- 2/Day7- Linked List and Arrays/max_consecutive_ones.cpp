class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n= arr.size();
        int c= 0;
        int ans= INT_MIN;
        if(arr[0]==1)
            c=1;
        
        for(int i=1; i<n; i++) {
            if(arr[i]==1) {
                c++;
            }
            else {
                ans= max(ans, c);
                c=0;
            }
        }
        ans= max(ans, c);
        return ans;
    }
};