#include<bits/stdc++.h>
using namespace std;

int kthelement(int arr1[], int arr2[], int m, int n, int k) {
    if(m>n) {
        return kthelement(arr2, arr1, n, m, k);
    }
        
    int low= max(0, k-m);
    int high= min(k, n);
        
    while(low <= high) {
        int cut1= (low+high) >> 1; 
        int cut2= k - cut1; 
        int l1= cut1 == 0 ? INT_MIN : arr1[cut1-1]; 
        int l2= cut2 == 0 ? INT_MIN : arr2[cut2-1];
        int r1= cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2= cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if(l1 > r2) {
            high= cut1-1;
        }
        else {
            low= cut1+1; 
        }
    }
    return 1; 
}

int main() {
    int arr1[]= {2, 3, 6, 7, 9};
    int arr2[]= {1, 4, 8, 10};

    int m= sizeof(arr1)/sizeof(arr1[0]);
    int n= sizeof(arr2)/sizeof(arr2[0]);
    int k= 5;
    
    cout<< "The kth element in the final array: "<< kthelement(arr1, arr2, m, n, k);
    return 0;
}