class Solution {
public:
    int mod = 1e9 + 7;
    int numDecodings(string s) {
        int n = s.length();
        vector<long long> dp(n + 2, 0LL);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else {
                long long res = 0;
                if (s[i] == '*') {
                    res = (9LL * dp[i + 1]) % mod;
                } else
                    res = dp[i + 1] % mod;
                res %= mod;
                if (i + 1 < s.length()) {
                    if (s[i] == '1') {
                        if (s[i + 1] == '*')
                            res += (9LL * dp[i + 2]);
                        else
                            res += dp[i + 2];
                    } else if (s[i] == '2') {
                        if (s[i + 1] == '*')
                            res += (6LL * dp[i + 2]);
                        else if (s[i + 1] <= '6')
                            res += dp[i + 2];
                    } else if (s[i] == '*') {
                        if (s[i + 1] == '*')
                            res += (15LL * dp[i + 2]);
                        else if (s[i + 1] <= '6')
                            res += (2LL * dp[i + 2]);
                        else
                            res += (1LL * dp[i + 2]);
                    }
                }

                dp[i] = res % mod;
            }
        }
        return (int)dp[0];
    }
    // long long f(string &s , int i,vector<long long>&dp){
    //     if(i==s.length())return 1;
    //     if(s[i]=='0')return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     long long res = 0;
    //     if(s[i]=='*'){
    //         res=(9LL*f(s,i+1,dp))%mod;
    //     }
    //     else res=f(s,i+1,dp)%mod;
    //     res%=mod;
    //     if(i+1<s.length()){
    //         if(s[i]=='1'){
    //         if(s[i+1]=='*')res+=(9LL*f(s,i+2,dp));
    //         else res+=f(s,i+2,dp);
    //         }
    //     else if(s[i]=='2'){
    //         if(s[i+1]=='*')res+=(6LL*f(s,i+2,dp));
    //         else if(s[i+1]<='6')res+=f(s,i+2,dp);
    //     }
    //     else if(s[i]=='*'){
    //         if(s[i+1]=='*')res+=(15LL*f(s,i+2,dp));
    //         else if(s[i+1]<='6')res+=(2LL*f(s,i+2,dp));
    //         else res+=(1LL*f(s,i+2,dp));
    //     }
    //     }

    //     return dp[i]= res%mod;
    // }
};