class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n= arr1.size();
        int m= arr2.size();

        int i=0, j=0;
        vector<int> ans;
        while(i<n && j<m) {
            if(arr1[i] < arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            }
            else {
                ans.push_back(arr2[j]);
                j++;
            }
        }

        while(i<n) {
            ans.push_back(arr1[i]);
            i++;
        }
        while(j<m) {
            ans.push_back(arr2[j]);
            j++;
        }

        int l= ans.size();
        double res;
        if(l%2!=0) {
            res= (double)ans[l/2];
        }
        else {
            res= (double)(ans[l/2]+ans[l/2-1])/2;
        }

        return res;
    }
};