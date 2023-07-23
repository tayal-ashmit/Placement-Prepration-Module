class Solution {
  public:
    int compareVersion(string version1, string version2) {
        if(version1==version2)
            return 0;
        
        int v1= version1.size();
        int v2= version2.size();
        int i=0, j=0;

        while(i<v1 || j<v2) {
            string t= "";
            while(i<v1 &&  version1[i] != '.') {
                t += version1[i++];
            }
            i++;
            int ch1= (t=="") ? 0 : stoi(t);
            
            t= "";
            while(j<v2 && version2[j] != '.') {
                t += version2[j++];
            }
            j++;
            int ch2= (t=="") ? 0 : stoi(t);

            if(ch1>ch2)
                return 1;
            else if(ch1<ch2)
                return -1;
        }

        return 0;
    }
};