class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n= arr.size();
        int k= 1;
        for(int i=1; i<n; i++) {
            if(arr[i-1] != arr[i]) {
                arr[k]= arr[i];
                k++;
            }
        }
        return k;
    }
};