class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)return "1";
        string ans = rle(countAndSay(n-1));
        return ans;
    }
    string rle(string s){
        string ans = "";
        int cnt = 1;
        int i = 1;
        for(i;i<s.length();i++){
            if(s[i] == s[i-1]){
                cnt++;
            }
            else{
                ans+=cnt+'0';
                ans+=s[i-1];
                cnt=1;
            }
        }
        ans+=cnt+'0';
        ans+=s[i-1];
                
        return ans;
    }
};