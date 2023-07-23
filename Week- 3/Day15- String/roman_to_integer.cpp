class Solution {
  public:
    int romanToInt(string s) {
        int sum= 0;
        unordered_map<char, int> map;
        vector<char> arr= {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        vector<int> val= {1, 5, 10, 50, 100, 500, 1000};

        for(int i=0; i<arr.size(); i++) {
            map[arr[i]]= val[i];
        }

        int i= 0;
        while(i < s.size()-1) {
            if(map[s[i]] < map[s[i+1]]){
                sum += map[s[i+1]]-map[s[i]];
                i += 2;
            }
            else {
                sum += map[s[i]];
                i++;
            }
        }
        
        if(i == s.size()-1) {
            sum += map[s[i]];
        }

        return sum;
    }
};