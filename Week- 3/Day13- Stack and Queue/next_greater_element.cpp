class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr, vector<int>& brr) {
        vector<int> ans;
        int q= arr.size();
        int n= brr.size();

        for(int i=0; i<q; i++) {
            int x= arr[i];
            int y=-1;
            for(int j=0; j<n; j++) {
                if(brr[j]==x) {
                    y=j;
                }
            }
            int k=-1;
            for(int j=y+1; j<n; j++) {
                if(brr[j]>x) {
                    k=brr[j];
                    break;
                }
            }
            ans.push_back(k);
        }
        return ans;
    }
};