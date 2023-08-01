class Solution {
public:
    static bool compare(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        vector<int>ans;
        sort(arr, arr+n, compare);
        
        int occupied[n];
        int order[n];
        for(int i=0; i<n; i++ ){
            occupied[i]= false;
        }

        int count=0;
        int sum=0;
        for(int i=0; i<n; i++) {
            for(int j=arr[i].dead-1; j>=0; j--) {
                if(occupied[j] == false) {
                    occupied[j]= true;
                    order[j]= i;
                    count++;
                    sum += arr[i].profit;
                    break;
                }
            }
        }

        ans.push_back(count);
        ans.push_back(sum);
        return ans;
    } 
};