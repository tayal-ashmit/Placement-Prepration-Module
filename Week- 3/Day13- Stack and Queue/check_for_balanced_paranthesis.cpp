class Solution {
public:
    bool isValid(string s) {
        stack<char> as;
        
        for(int i=0; i<s.length(); i++) {
            if(as.size()==0)
                as.push(s[i]);
            else if(s[i]==')' && as.top()=='(')
                as.pop();
            else if(s[i]==']' && as.top()=='[')
                as.pop();
            else if(s[i]=='}' && as.top()=='{')
                as.pop();
            else
                as.push(s[i]);
        }

        if(as.size()==0)
            return true;
        return false;
    }
};