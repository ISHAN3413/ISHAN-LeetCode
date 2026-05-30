class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0;i<s.length();i++){
            ans+=f(s , string(1,s[i]) ,i+1);
        }
        return ans;
    }
    int f(string &s , string curr , int i ){
        int cnt = p(curr)?1:0;
        if(i>=s.length())return cnt;
        return cnt + f(s , curr + s[i] , i+1);
    }
    bool p(string s){
        int l = 0;
        int r = s.length()-1;
        while(l<=r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
};