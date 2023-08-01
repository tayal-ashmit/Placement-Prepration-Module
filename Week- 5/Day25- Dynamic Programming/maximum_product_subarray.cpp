class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int max_suff= 1;
        int min_suff= 1;

        int ans= INT_MIN;
        int maxi= 1;
        int mini= 1;
        for(int x: arr) {
            max_suff= max(x, max(mini*x, maxi*x));
            min_suff= min(x, min(mini*x, maxi*x));

            maxi= max_suff;
            mini= min_suff;
            ans= max(ans, maxi);
        }

        return ans;
    }
}