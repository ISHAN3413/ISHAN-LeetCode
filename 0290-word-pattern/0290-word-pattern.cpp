class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char,string> key1;
        std::unordered_map<string,char> key2;
        int j=0;
        int i=0;
        while(i<pattern.length()&&j<s.length()){
            string r="";
            while(s[j]!=' '&&j<s.length()){
                r+=s[j];
                j++;
            }
            j++;
            if(key1.count(pattern[i])&&key1[pattern[i]]!=r)return false;
            if(key2.count(r)&&key2[r]!=pattern[i])return false;
            key1[pattern[i]]=r;
            key2[r]=pattern[i];
            i++;
        }
        
        return i==pattern.length()&&j>=s.length();
    }
};