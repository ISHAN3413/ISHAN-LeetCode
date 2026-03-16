class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
       vector<int> sa (26,0);
       vector<int> ta (26,0);
       for(int i=0;i<s.length();i++){
        sa[s[i]-'a']++;
        ta[t[i]-'a']++;
       }
       return sa==ta;
    }
};