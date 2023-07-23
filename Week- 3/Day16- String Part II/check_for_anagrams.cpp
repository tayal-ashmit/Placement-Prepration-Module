class Solution {
public:
    bool isAnagram(string as, string bs) {
        int a= as.length();
        int b= bs.length();

        int arr[26]= {0};
        for(int i=0; i<a; i++)
            arr[as[i]-'a']++;
        
        int brr[26]= {0};
        for(int i=0; i<b; i++)
            brr[bs[i]-'a']++;
        
        for(int i=0; i<26; i++) {
            if(arr[i] != brr[i])
                return false;
        }
        
        return true;
    }
};