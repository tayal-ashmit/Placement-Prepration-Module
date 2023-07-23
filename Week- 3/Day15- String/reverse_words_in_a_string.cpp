class Solution {
public:
    string reverseWords(string s) {
        int i= 0;
        int n= s.size();
        vector<string> arr;

        while(i<n) {
            string str="";

            while(i<n && s[i]==' ')
                i++;
            
            while(i<n && s[i]!=' ')
                str += s[i++];
            
            if(str=="" || str==" ")
                continue;
            
            arr.push_back(str);
        }

        string k= arr[arr.size()-1];
        for(int i=arr.size()-2; i>=0; i--)
            k += " " + arr[i];

        return k;
    }
};