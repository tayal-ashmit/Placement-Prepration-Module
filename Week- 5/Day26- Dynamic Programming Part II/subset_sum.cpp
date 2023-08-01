class Solution {
public:
    bool spaceOptimize(vector<int>&nums,int target){
        int n= nums.size();
        vector<bool> curr(target+1 ,0);
        vector<bool> next(target+1, 0);
         
        for(int i=0; i<n; i++) {
            next[0] = true;
        }

        for(int index=n-1; index>=0; index--){
            for(int j=1; j<=target; j++) {
                bool include= 0;
                if(j-nums[index] >= 0)
                    include= next[j-nums[index]];
                bool exclude= next[j];
                curr[j]= include || exclude;
            }
            
            next= curr;
        }

        return curr[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum= accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0)
            return false;

        int target= sum/2;
        int index= 0;
        bool ans= spaceOptimize(nums,target);

        return ans;
    }
};