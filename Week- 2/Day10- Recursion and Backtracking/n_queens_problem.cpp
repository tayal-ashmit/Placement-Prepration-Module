class Solution {
public:
    bool check(vector<string> temp, int row, int col, int n) {
        int r= row;
        int c= col;

        while(c>=0) {
            if(temp[row][c]=='Q')
                return false;
            c--;
        }

        r= row;
        c= col;
        while(r>=0 && c>=0) {
            if(temp[r][c]=='Q')
                return false;
            c--;
            r--;
        }

        r= row;
        c= col;
        while(r<n && c>=0) {
            if(temp[r][c]=='Q')
                return false;
            r++;
            c--;
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& temp, int n, int co) {
        if(co == n) {
            ans.push_back(temp);
            return;
        }

        for(int ro=0; ro<n; ro++) {
            if(check(temp, ro, co, n)) {
                temp[ro][co]= 'Q';
                solve(ans, temp, n, co+1);
                temp[ro][co]= '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string s(n, '.');
        for(int i=0; i<n; i++) {
            temp[i]= s;
        }

        solve(ans, temp, n, 0);

        return ans;
    }
};