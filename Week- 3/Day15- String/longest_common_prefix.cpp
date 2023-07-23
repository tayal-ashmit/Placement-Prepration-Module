class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        string ans= "";
        sort(strs.begin(), strs.end());
        int k= min(strs[0].size(), strs[n-1].size());
        
        for(int i=0; i<k; i++){
            if(strs[0][i] == strs[strs.size()-1][i]) {
                ans += strs[0][i];
            }
            else {
                return ans;
            }
        }
        return ans;
    }
};

