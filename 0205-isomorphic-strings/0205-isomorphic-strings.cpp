class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())return false;
        std::unordered_map<char,char> st;
        std::unordered_map<char,char> ts;
        for(int i=0;i<s.length();i++){
            char cs=s[i];
            char ct=t[i];
            if(st.count(cs)&&st[cs]!=ct)return false;
            if(ts.count(ct)&&ts[ct]!=cs)return false;
            st[cs]=ct;
            ts[ct]=cs;
        }
        return true;
    }
};