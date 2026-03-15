class Solution {
public:
    int scoreOfString(string s) {
        int k=0;
        for(int i=1;i<s.length();i++){            
           if(s[i-1]>=s[i])k=k+(s[i-1]-s[i]);
           else k=k+(s[i]-s[i-1]);
        }
        return k;
    }
};