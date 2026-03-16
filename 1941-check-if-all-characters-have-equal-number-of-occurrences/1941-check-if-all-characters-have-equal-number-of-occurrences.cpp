class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int o[26]={0};
        for(int i=0;i<s.length();i++){
            o[s[i]-'a']++;
        }
        int a=0;
        for(int i=0;i<26;i++){
            if(o[i]!=0){
                a=o[i];
               break;
            }
        }
       for(int i=0;i<26;i++){
        if(o[i]!=0 && a!=o[i])return 0;
       }
       return 1;

    }
};