class Solution {
public:
    string makeFancyString(string s) {
        string s1;
        int i;
        int j=1;
        for(i=0;i<s.length();i++){
            if(i>0 && s[i-1]==s[i]){
                j++;
            }
            else j=1;
            if(j<3)s1.push_back(s[i]);
        }
       
       return s1;
    }
};