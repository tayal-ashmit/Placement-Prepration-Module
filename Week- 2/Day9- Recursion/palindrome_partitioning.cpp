class Solution {
public:
    bool ispalindrome(string s, int i, int j) {
        while(i<=j) {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& temp, string s, int n, int i) {
        if(i==n) {
            ans.push_back(temp);
            return;
        }

        for(int j=i; j<n; j++) {
            if(ispalindrome(s, i, j)) {
                temp.push_back(s.substr(i, j-i+1));
                solve(ans, temp, s, n, j+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(ans, temp, s, s.length(), 0);
        
        return ans;
    }
};