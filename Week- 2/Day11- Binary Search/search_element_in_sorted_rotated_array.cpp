class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n= arr.size();
        int l=0, h=n-1;

        while(l <= h) {
            int mid= (l+h)/2;

            if(arr[mid] == key) {
                return mid;
            }

            if(arr[l] < arr[mid]) {
                if(key >= arr[l] && key <= arr[mid])
                    h= mid-1;
                else
                    l= mid+1;
            }
            else if(arr[l] > arr[mid]) {
                if(key >= arr[mid] && key <= arr[h])
                    l= mid+1;
                else
                    h= mid-1;
            }
            else
                l++;
        }
        
        return -1;
    }
};