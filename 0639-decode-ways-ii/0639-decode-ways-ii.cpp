class Solution {
public:
int mod = 1e9 + 7;
    int numDecodings(string s) {
        int n = s.length();
        vector<long long> dp(n+1 , -1LL);
        return (int)f(s,0,dp);
    }
    long long f(string &s , int i,vector<long long>&dp){
        if(i==s.length())return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        long long res = 0;
        if(s[i]=='*'){
            res=(9LL*f(s,i+1,dp))%mod;
        }
        else res=f(s,i+1,dp)%mod;
        res%=mod;
        if(i+1<s.length()){
            if(s[i]=='1'){
            if(s[i+1]=='*')res+=(9LL*f(s,i+2,dp));
            else res+=f(s,i+2,dp);
            }
        else if(s[i]=='2'){
            if(s[i+1]=='*')res+=(6LL*f(s,i+2,dp));
            else if(s[i+1]<='6')res+=f(s,i+2,dp);
        }
        else if(s[i]=='*'){
            if(s[i+1]=='*')res+=(15LL*f(s,i+2,dp));
            else if(s[i+1]<='6')res+=(2LL*f(s,i+2,dp));
            else res+=(1LL*f(s,i+2,dp));
        }
        }
        
        return dp[i]= res%mod;
    }
};