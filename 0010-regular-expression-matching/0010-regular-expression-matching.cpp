class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(s,p,n-1,m-1,dp);
    }
    bool f(string &s , string &p ,int i , int j,vector<vector<int>>&dp){
        if(i<0){
            while(j>=0){
                if(p[j]!='*')return false;
                j-=2;
            }
            return true;
        }
        if(j<0)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(p[j]=='.'||p[j]==s[i]){
            return dp[i][j] = f(s,p,i-1,j-1,dp);
        }
        if(p[j]=='*'){
            bool a = f(s,p,i,j-2,dp);
            bool b = false;
            if(p[j-1]==s[i] || p[j-1]=='.'){
                b=f(s,p,i-1,j,dp);
            }
            return dp[i][j] =( a||b);
        }
        return dp[i][j] = false;
    }
};